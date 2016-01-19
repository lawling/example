#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 10 (public10.c)
 *
 * Tests calling load_program() with an invalid value for program_size.
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
  int i;

  assert(load_program(&spim, program, MAX_MEMORY + 4) == 0);

  /* verify that the program was not in fact loaded */
  for (i= 0; i < 4; i++)
    assert(spim.memory[i] == 0);

  printf("Success!\n");  /* all assertions succeeded */

  return 0;
}
