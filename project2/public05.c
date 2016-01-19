#include <stdio.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 5 (public05.c)
 *
 * Tests using disassemble() to print more instructions.
 */

#define MEMORY_SZ ((1024 * 48) / 4)

int main() {
  Word memory[MEMORY_SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000,
                           0x69b00000, 0xa7800000, 0x00000000};

  disassemble(memory, 8, 3);

  return 0;
}