#include <stdio.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 2 (public02.c)
 *
 * Tests the basic operation of print_instruction() for more instructions.
 */

#define SZ 5

int main() {
  Word words[SZ]= {0x76000040, 0x8a000020, 0x9900007c, 0xc8000000, 0xd7000000};
  int i;

  for (i= 0; i < SZ; i++)
    print_instruction(words[i]);

  return 0;
}