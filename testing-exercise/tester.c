#include <stdio.h>
#include "my-string.h"

int main() {
  My_string s, t, check;

  init(&s);
  init(&t);
  init(&check);

  assign(&s, "abcdefghijk");
  assign(&t, "xyz");

  replace_between(&s, 3, 4, t);
  assign(&check, "abcxyzhijk");
  if (equal(s, check))
    printf("Test 1 passed!\n");
  else printf("Test 1 failed :-(\n");

  copy(&s, t);
  assign(&check, "xyz");
  if (equal(s, check))
    printf("Test 2 passed!\n");
  else printf("Test 2 failed :-(\n");

  clear(&s);
  clear(&t);
  clear(&check);

  return 0;
}
