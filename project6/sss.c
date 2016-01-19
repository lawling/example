/*
This file is written by
Yuan Liang
It include implementations of functions
and helper functions 
*/
#include "./sss.h"
/*helper function declarations */
static void wait_all_child();
static int Execute(char *cmd, Commands);
static int check(const void *ptr, const char *msg, int terminate_program);
static char **read_file(const char *file_name);
/*helper function*/
static void wait_all_child(int *status)
{
	while (waitpid(-1, status, 0))
		if (errno == ECHILD)
			break;

}

static void child_clear(char **s, int end, Commands * c)
{
	int j;
	for (j = 0; j != end; j++)
		free(s[j]);
	free(s);
	clear_commands(c);
}

static int Execute(char *cmd, Commands c)
{
	int i, j, k, ins_end, status = 1;
	char **args;
	int fd = 0;
	int *ins_idx = calloc(sizeof(int), 128);
	char *dir_s = malloc(10);
	check(cmd, "not cmd for execution", false);

	args = split(cmd);

/*find redirection in cmds*/
	for (j = 0, i = 0; args[i] != NULL; i++)
		if (strcmp(args[i], "<") == 0) {
			free(args[i]);
			args[i] = NULL;
			/*reallocate */
			ins_idx[j + 1] = i + 1;
			dir_s[j] = '<';
			j++;

		} else if (strcmp(args[i], ">") == 0) {
			free(args[i]);
			args[i] = NULL;

			ins_idx[j + 1] = i;
			dir_s[j] = '>';
			j++;
		}
	dir_s[j] = ' ';
	ins_end = i;
	ins_idx[j + 1] = i;

/*run command and perform redirection if necessary*/
	for (i = 0, j = 0, k = 0; i < ins_end; i++) {
		if (dir_s[k] == '>') {
			k++;
			i = ins_idx[j++];
			if (fork() == 0) {
				fd = open(args[ins_idx[j]],
					  O_CREAT | O_WRONLY,
					  S_IRWXU | S_IRWXG);
				dup2(fd, STDOUT_FILENO);
				execvp(args[i], &args[i]);
				close(fd);
				free(ins_idx);
				free(dir_s);
				child_clear(args, ins_end, &c);
				exit(0);
			} else {
				wait_all_child(&status);
			}
			i = ins_idx[++j];

		} else if (dir_s[k] == '<') {
			k++;
			i = ins_idx[j++];
			if (fork() == 0) {
				fd = open(args[ins_idx[j]],
					  O_CREAT | O_RDONLY,
					  S_IRWXU | S_IRWXG);
				dup2(fd, STDIN_FILENO);
				execvp(args[i], &args[i]);
				close(fd);
				free(ins_idx);
				free(dir_s);
				child_clear(args, ins_end, &c);
				exit(0);
			} else {
				wait_all_child(&status);
			}
			i = ins_idx[++j];
		} else if (dir_s[k] == ' ') {
			i = ins_idx[j++];
			if (fork() == 0) {
				execvp(args[i], &args[i]);
				free(ins_idx);
				free(dir_s);
				child_clear(args, ins_end, &c);
				exit(0);
			} else {
				wait_all_child(&status);
			}
			i = ins_idx[j];
			break;
		}
	}
	free(ins_idx);
	free(dir_s);
	for (j = 0; j != ins_end; j++)
		free(args[j]);
	free(args);

	return status;
}

static int check(const void *ptr, const char *msg, int t)
{
	if (ptr == NULL) {
		perror(msg);
		if (t == true)
			exit(0);
		return 0;
	}
	return 1;
}

/*read file and return string from file*/
static char **read_file(const char *file_name)
{
	FILE *f;
	int cap_size = 4, s_len = 256, i = 0;
	char **ss = malloc(cap_size * sizeof(char *));
	check(ss, "memory allocation fail", true);

	ss[cap_size - 1] = NULL;

	f = fopen(file_name, "r");
	check(f, "file cannot be open", true);

	i = 0;
	do {
		if (i >= cap_size) {
			cap_size *= 2;
			ss = realloc(ss, cap_size * sizeof(char *));
			check(ss, "memory rellocation fail\n"
			      " continue possible data lost", false);
		}

		ss[i] = malloc(s_len);
	}
	while (fgets(ss[i++], s_len, f) != NULL);
	free(ss[i - 1]);
	for (i = i - 1; i < cap_size; i++)
		ss[i] = NULL;

	fclose(f);
	return ss;
}

/*end helper function*/

Commands read_commands(const char *compile_cmds, const char *test_cmds)
{
	Commands c;
	check(compile_cmds, "compile_cmds invalid", true);
	check(test_cmds, "test_cmds invalid", true);

	c.compile_cmds = read_file(compile_cmds);
	c.test_cmds = read_file(test_cmds);

	return c;
}

void clear_commands(Commands * const commands)
{

	int i = 0;
	check(commands, "commands are NULL", true);

	for (i = 0; commands->compile_cmds[i] != NULL; i++)
		free(commands->compile_cmds[i]);

	free(commands->compile_cmds);

	for (i = 0; commands->test_cmds[i] != NULL; i++)
		free(commands->test_cmds[i]);
	free(commands->test_cmds);

	return;
}

int compile_program(Commands commands)
{
	int i, status = 1;
	if (check(commands.compile_cmds, "no compile commands", false) ==
	    0)
		return 0;

	for (i = 0; commands.compile_cmds[i] != NULL; i++) {
		status = Execute(commands.compile_cmds[i], commands);
		if (WIFEXITED(status) >= 0) {
			if (WEXITSTATUS(status) == EXIT_SUCCESS) ;

		}
	}

	if (status == 0)
		return 1;

	return 0;
}

int test_program(Commands commands)
{

	int i, status = 0, cnt = 0;
	if (check(commands.test_cmds, "no compile commands", false) == 0)
		return 0;

	for (i = 0; commands.test_cmds[i] != NULL; i++) {
		status = Execute(commands.test_cmds[i], commands);
		if (WIFEXITED(status) != 0) {
			if (WEXITSTATUS(status) == EXIT_SUCCESS)
				cnt++;
		}
	}
	return cnt;
}
