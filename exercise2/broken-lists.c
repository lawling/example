#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "broken-lists.h"

/* (c) Larry Herman, 2015.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* is correct */
Node *create_list(int arr[], int size) {
  Node *n, *list= NULL;

  if (arr != NULL && size != 0)
    while (size-- > 0) {

      n= malloc(sizeof(*n));
      if (n == NULL)
        return NULL;  /* we just return NULL if memory allocation fails */
      else {
        n->value= arr[size];
        n->next= list;
        list= n;
      }
    }

  return list;
}

/* is correct, provided the user passes in a string that is large enough to
 * store the elements of the list, with spaces between them
 */
void list_to_string(Node *list, char result[]) {
  char temp[MAX_LEN + 1];

  strcpy(result, "");  /* clear out any existing contents */

  while (list != NULL) {
    sprintf(temp, "%d", list->value);

    if (strlen(result) + strlen(temp) + 1 < MAX_LEN) {
      strcat(result, temp);

      /* add a space if it's not the last element */
      if (list->next != NULL)
        strcat(result, " ");
    }

    list= list->next;
  }
}

/*****************************************************************************/
/*       the functions you have to write or correct are below this           */
/*****************************************************************************/

/* this function's parameter is a pointer to the head node of a list; it
 * should release all of the memory of the list, and set the head pointer
 * (meaning the pointer that its parameter points to) to NULL
 */
void clear(Node **list) {
     if( ((*list)->next) != NULL)
           clear(& ((*list)->next));
     free( *list );
     *list = NULL;
     return ;
}

/* should return the sum of the values in the even-numbered positions of a
 * list (the value in the second node, the fourth node, etc.), but has a bug
 * (the first node is considered to be position #1, in other words, the list
 * has no position zero)
 */
int sum_even(Node *list) {
  Node *ptr= list->next;
  int sum= 0;

  if (list != NULL)
    while (ptr != NULL) {
      sum += ptr->value;
    if(ptr->next == NULL)
      break;
      ptr= ptr->next->next;
    }  

  return sum;
}

/* should remove the last element from a list, returning 1 upon success or 0
 * if start is NULL, but has a bug
 */
int remove_last(Node **start) {
  Node *prev= NULL, *travel;
  int result= 0;

  if (start != NULL) {

    result= 1;

    travel= *start;
    while (travel != NULL && travel->next != NULL) {
      prev= travel;
      travel= travel->next;
    }

    if (prev != NULL) {
      free(prev->next);
      prev->next= NULL;
    }else free(travel);

  }

  return result;
}

/* should remove the first element from a list, returning 1 upon success or
 * 0 if the list is empty or start is NULL, but has a bug
 */
int remove_first(Node **start) {
  Node *temp= NULL;
  int result= 0;

  if (start != NULL && *start != NULL) {

    result= 1;
    temp= *start;
    *start= (*start)->next;
    free(temp);

  }

  return result;
}
