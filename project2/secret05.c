#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 5 (secret05.c)
 *
 * Tests calling disassemble() with a valid value for starting_address,
 * but a too-large value for num_words, which would lie outside of the
 * SPIM's memory; this would be invalid.
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  assert(disassemble(memory, 4, (MEMORY_SZ * 4)) == -1);

  printf("The assertion succeeded!\n");

  return 0;
}
