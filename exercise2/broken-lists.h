/* (c) Larry Herman, 2015.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

typedef struct node {
  int value;
  struct node *next;
} Node;

/* for simplicity it's assumed that no list will ever have enough elements
 * that a string containing the elements will be longer than this
 */
#define MAX_LEN 1000

Node *create_list(int arr[], int size);
void list_to_string(Node *list, char result[]);
int sum_even(Node *list);
int remove_last(Node **start);
int remove_first(Node **start);
void clear(Node **list);
