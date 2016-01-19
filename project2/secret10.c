#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 10 (secret10.c)
 *
 * Tests calling valid_instruction() with various valid instructions that
 * were not tested in the public tests.
 */

#define SZ 17

int main() {
  Word instrs[SZ]= {0x1a980000, 0x210b0000, 0x33300000, 0x6aa00000, 0xc2000000,
                    0xc4000000, 0xc6000000, 0xd3000000, 0xd5000000, 0xd7000000,
                    0x4120001e, 0x42100000, 0xb5002ee0, 0xb4b02afc, 0x7700299c,
                    0x8900baa8, 0x8800aaa4};
  int i;

  for (i= 0; i < SZ; i++)
    assert(valid_instruction(instrs[i]) == 1);

  printf("All assertions succeeded!\n");

  return 0;
}
