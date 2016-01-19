#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 17 (secret17.c)
 *
 * Tests whether valid_instruction() ignores invalid values in fields
 * that are not used by instructions, meaning that they have no effect on
 * the instructions' validity.
 */

int main() {
  /* halt instruction with invalid first register operand */
  assert(valid_instruction(0x0f000000) == 1);

  /* read instruction with invalid second register operand */
  assert(valid_instruction(0xc1d00000) == 1);

  /* neg instruction with invalid third register operand */
  assert(valid_instruction(0x333d0000) == 1);

  /* add instruction with invalid memory address (not divisible by 4) */
  assert(valid_instruction(0x1a980001) == 1);

  /* add instruction with invalid memory address (too large) */
  assert(valid_instruction(0x1a98ddd1) == 1);

  printf("All assertions succeeded!\n");

  return 0;
}
