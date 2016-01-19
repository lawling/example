#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 4 (public04.c)
 *
 * Tests loading and running a multiple-instruction program for a few
 * instructions.
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
  int num_instr_executed;

  load_program(&spim, program, PROGRAM_SIZE);

  run_SPIM_program(&spim, 4, &num_instr_executed, 0);

  assert(spim.registers[R01] == 9);
  assert(spim.registers[R02] == 2);
  assert(spim.registers[R03] == 11);
  assert(spim.registers[R04] == 13);

  printf("Success!\n");  /* all assertions succeeded */

  return 0;
}
