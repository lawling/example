#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 15 (secret15.c)
 *
 * Tests calling valid_instruction() with instructions that incorrectly
 * use either R0 or R11 as their first register operand.
 */

int main() {
  assert(valid_instruction(0x80000004) == 0);
  assert(valid_instruction(0x7b000004) == 0);

  printf("Both assertions succeeded!\n");

  return 0;
}
