#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 6 (secret06.c)
 *
 * Tests calling disassemble() with num_words == 0, which is valid, and
 * should just result in no output.
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  assert(disassemble(memory, 4, 0) == 0);

  printf("The assertion succeeded!\n");

  return 0;
}
