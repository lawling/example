#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 2 (public02.c)
 *
 * Tests calling load_program() to load a small multiple-instruction
 * program into memory.
 */

#define PROGRAM_SIZE 4

int main() {
  Machine spim= {{0}};  /* everything, including the PC, will be set to zero */
  Word program[PROGRAM_SIZE]= {
    0x81000009,  /*  0: li   R01    9 */
    0x82000002,  /*  4: li   R02    2 */
    0x13210000,  /*  8: add  R03  R02  R01 */
    0x14320000   /*  c: add  R04  R03  R02 */
  };

  load_program(&spim, program, PROGRAM_SIZE);

  assert(spim.memory[0] == 0x81000009);
  assert(spim.memory[1] == 0x82000002);
  assert(spim.memory[2] == 0x13210000);
  assert(spim.memory[3] == 0x14320000);

  printf("Success!\n");  /* all assertions succeeded */

  return 0;
}
