#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 12 (secret12.c)
 *
 * Tests calling valid_instruction() with instructions that have invalid
 * register operands.
 */

int main() {
  /* invalid first register operand- too large */
  assert(valid_instruction(0xde000000) == 0);

  /* invalid second register operand- too large */
  assert(valid_instruction(0x32f00000) == 0);

  /* invalid third register operand- too large */
  assert(valid_instruction(0x252f0000) == 0);

  printf("All assertions succeeded!\n");

  return 0;
}
