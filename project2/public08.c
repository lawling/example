#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 8 (public08.c)
 *
 * Tests the basic operation of valid_instruction() on some valid
 * instructions.
 */

int main() {
  assert(valid_instruction(0x12100000) == 1);
  assert(valid_instruction(0x25430000) == 1);
  assert(valid_instruction(0x58760000) == 1);
  assert(valid_instruction(0x39a00000) == 1);
  assert(valid_instruction(0x69b00000) == 1);
  assert(valid_instruction(0xa7800000) == 1);
  assert(valid_instruction(0x00000000) == 1);

  printf("All assertions succeeded!\n");

  return 0;
}
