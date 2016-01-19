#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 9 (public09.c)
 *
 * Tests loading and running a program that has an error during execution.
 */

#define PROGRAM_SIZE 11

int main() {
  Machine spim= {{0}};  /* everything, including the PC, will be set to zero */
  Word program[PROGRAM_SIZE]= {
    0x81000000,  /*  0: li     R01  00000 */
    0x82000001,  /*  4: li     R02  00001 */
    0x83000001,  /*  8: li     R03  00001 */
    0x84000001,  /*  c: li     R04  00001 */
    0x8500000a,  /* 10: li     R05  00010 */
    0x11120000,  /* 14: add    R01  R01  R02 */
    0x42200030,  /* 18: shl    R02  R02  00030 (this instruction is invalid) */
    0x14430000,  /* 1c: add    R04  R04  R03 */
    0xb4500014,  /* 20: bne    R04  R05  00020 */
    0xd1000000,  /* 24: write  R01 */
    0x00000000   /* 28: halt */
  };
  int num_instr_executed;

  load_program(&spim, program, PROGRAM_SIZE);

  assert(run_SPIM_program(&spim, 100, &num_instr_executed, 0) ==
         INVALID_INSTRUCTION);
  assert(num_instr_executed == 6);

  printf("Success!\n");  /* both assertions succeeded */

  return 0;
}
