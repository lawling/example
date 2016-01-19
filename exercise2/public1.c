#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "broken-lists.h"

/* (c) Larry Herman, 2015.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */
void printList(Node * list){
while(list != NULL){   
printf("%d ",list->value);
   list = list->next;
}

}
int main(void) {
  int arr[]= {10, 20, 30, 40, 50, 60, 70};
  Node *list= NULL;
  char elements[MAX_LEN + 1];
/*this part is written by Yuan Liang*/
  int arr1[]={10,20,30,40,50,60};
   Node *myList=NULL;
   char results[MAX_LEN+1];
   myList=create_list(arr1,sizeof(arr1)/sizeof(arr1[0]));
  if(list == NULL){

}
/*   test remove first*/
    remove_first(&myList);
    printList(myList);
    list_to_string(myList,results);
    assert(strcmp(results,"20 30 40 50 60")==0);
   
/*end*/
  list= create_list(arr, sizeof(arr) / sizeof(arr[0]));

  /* test sum_even() */
  assert(sum_even(list) == 120);

  /* test remove_last() */
  remove_last(&list);
  remove_first(&list);
  printList(list);
  list_to_string(list, elements);
  assert(strcmp(elements, "20 30 40 50 60") == 0);

  printf("Score!\n");  /* both assertions passed */

  /* if your clear() function works, this program should not have any memory
     leaks, and list should be NULL afterwards */
  clear(&list);

  return 0;
}
