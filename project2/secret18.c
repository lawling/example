#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 18 (secret18.c)
 *
 * Tests passing NULL into disassemble()'s array parameter.
 */

int main() {
  assert(disassemble(NULL, 0, 7) == -1);

  printf("The assertion succeeded!\n");

  return 0;
}
