#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 13 (secret13.c)
 *
 * Tests calling valid_instruction() with instructions that have invalid
 * memory addresses that are too large, given the SPIM's memory size.
 */

int main() {
  assert(valid_instruction(0x7400fdc8) == 0);
  assert(valid_instruction(0x7400e000) == 0);

  printf("Both assertions succeeded!\n");

  return 0;
}
