#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 19 (secret19.c)
 *
 * Tests passing NULL into encode_instruction()'s pointer parameter.
 */

int main() {
  assert(encode_instruction(LW, R11, R00, R00, 64, NULL) == 0);

  printf("The assertion succeeded!\n");

  return 0;
}
