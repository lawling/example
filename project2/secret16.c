#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 16 (secret16.c)
 *
 * Tests calling valid_instruction() with shl instructions that are
 * incorrectly shifting by more than 31 bit positions.
 */

int main() {
  assert(valid_instruction(0x43200020) == 0);
  assert(valid_instruction(0x43200021) == 0);

  printf("Both assertions succeeded!\n");

  return 0;
}
