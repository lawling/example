#include <stdio.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 1 (public01.c)
 *
 * Tests the basic operation of print_instruction() for some instructions.
 */

#define SZ 7

int main() {
  Word words[SZ]= {0x12100000, 0x25430000, 0x58760000, 0x39a00000, 0x69b00000,
                   0xa7800000, 0x00000000};
  int i;

  for (i= 0; i < SZ; i++)
    print_instruction(words[i]);

  return 0;
}