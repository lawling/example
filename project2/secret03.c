#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 3 (secret03.c)
 *
 * Tests calling disassemble() with a negative value for starting_address,
 * which is invalid (it would lie outside of the SPIM's memory).
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  assert(disassemble(memory, -4, 1) == -1);

  printf("The assertion succeeded!\n");

  return 0;
}
