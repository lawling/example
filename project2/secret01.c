#include <stdio.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 1 (secret01.c)
 *
 * Tests calling disassemble() with various valid instructions (different
 * from the ones used in the public tests).
 */

#define SZ 18

int main() {
  Word words[SZ]= {0x1a980000, 0x210b0000, 0x33300000, 0x6aa00000, 0xc2000000,
                   0xc4000000, 0xc6000000, 0xd3000000, 0xd5000000, 0xd7000000,
                   0x4120001e, 0x42100000, 0xb5002ee0, 0xb4b02afc, 0x7700299c,
                   0x8900baa8, 0x8800aaa4, 0x00000000};
  int i;

  for (i= 0; i < SZ; i++)
    print_instruction(words[i]);

  return 0;
}
