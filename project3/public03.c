#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 3 (public03.c)
 *
 * Tests loading and running a one-instruction program for one instruction.
 */

#define PROGRAM_SIZE 1

int main() {
  Machine spim= {{0}};  /* everything, including the PC, will be set to zero */
  Word program[PROGRAM_SIZE]= {
    0x81000009  /*  0: li   R01    9 */
  };
  int num_instr_executed;

  load_program(&spim, program, PROGRAM_SIZE);

  run_SPIM_program(&spim, 1, &num_instr_executed, 0);

  assert(spim.registers[R01] == 9);

  printf("Success!\n");  /* the assertion succeeded */

  return 0;
}
