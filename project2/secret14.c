#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 14 (secret14.c)
 *
 * Tests calling valid_instruction() with instructions that have invalid
 * memory addresses that are not divisible by 4.
 */

int main() {
  assert(valid_instruction(0x77004321) == 0);
  assert(valid_instruction(0x77004327) == 0);

  printf("Both assertions succeeded!\n");

  return 0;
}
