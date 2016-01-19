#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 10 (public10.c)
 *
 * Tests the return value of disassemble in some simple cases.
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  assert(disassemble(memory, 0, 7) == 7);
  assert(disassemble(memory, 8, 3) == 3);

  printf("Both assertions succeeded!\n");

  return 0;
}
