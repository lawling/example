#include<stdio.h>
#include<stdlib.h>
unsigned int 
str_to_unsigned_int(char *str)
{
	int		offset = '0' - 0;
	unsigned int	re_value = 0, counter = 0;
	char           *end_cptr = str;
	while (*end_cptr != '\0')
		end_cptr++;
	while (end_cptr != str) {
		end_cptr--;
		re_value |= ((*end_cptr - offset) & (0x1)) << counter;
		counter++;
	}

	return re_value;
}
int 
main()
{
	int            *ptr = NULL;
	int		i = *ptr;
	printf("1011 is %u \n ", str_to_unsigned_int("1011"));
	printf(" i = %d \n", i);

}
