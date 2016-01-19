#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 11 (secret11.c)
 *
 * Tests calling valid_instruction() with an instruction that has an
 * invalid opcode.
 */

int main() {
  assert(valid_instruction(0xe0000000) == 0);

  printf("The assertion succeeded!\n");

  return 0;
}
