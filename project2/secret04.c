#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 4 (secret04.c)
 *
 * Tests calling disassemble() with a too-large value for
 * starting_address, which would lie outside of the SPIM's memory; this
 * would be invalid.
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  assert(disassemble(memory, (MEMORY_SZ * 4) + 4, 1) == -1);

  printf("The assertion succeeded!\n");

  return 0;
}
