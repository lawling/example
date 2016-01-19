#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 9 (public09.c)
 *
 * Tests the basic operation of valid_instruction() on an invalid
 * instruction.
 */

int main() {
  assert(valid_instruction(0xffffffff) == 0);

  printf("The assertion succeeded!\n");

  return 0;
}
