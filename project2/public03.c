#include <stdio.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 3 (public03.c)
 *
 * Tests the basic operation of print_instruction() for more instructions.
 */

#define SZ 2

int main() {
  Word words[SZ]= {0x42300008, 0xb5600018};
  int i;

  for (i= 0; i < SZ; i++)
    print_instruction(words[i]);

  return 0;
}