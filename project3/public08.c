#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 7 (public07.c)
 *
 * Tests loading and running a more complex program that uses some different
 * instructions.
 */

#define PROGRAM_SIZE 13

int main() {
  Machine spim= {{0}};  /* everything, including the PC, will be set to zero */
  Word program[PROGRAM_SIZE]= {
    0x81000001,  /*  0: li     R01  00001 */
    0xa2100000,  /*  4: move   R02  R01 */
    0x83000006,  /*  8: li     R03  00006 */
    0xa4100000,  /*  c: move   R04  R01 */
    0x24420000,  /* 10: mul    R04  R04  R02 */
    0x12210000,  /* 14: add    R02  R02  R01 */
    0xb2300010,  /* 18: bne    R02  R03  00016 */
    0x94000024,  /* 1c: sw     R04  00036 */
    0x00000000   /* 20: halt */
  };
  int num_instr_executed;

  load_program(&spim, program, PROGRAM_SIZE);

  run_SPIM_program(&spim, 100, &num_instr_executed, 0);

  /* the assertion uses a memory address divided by 4 to make it easy to see
     which SPIM memory location is being tested */
  assert(spim.memory[36 / 4] == 0x78);

  printf("Success!\n");  /* all assertions succeeded */

  return 0;
}
