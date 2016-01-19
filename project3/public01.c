#include <stdio.h>
#include <assert.h>
#include "machine.h"
#include "interpreter.h"

/*
 * CMSC 216, Fall 2015, Project #3
 * Public test 1 (public01.c)
 *
 * Tests calling load_program() to load a simple one-instruction program.
 */

#define PROGRAM_SIZE 1

int main() {
  Machine spim;
  Word program[PROGRAM_SIZE]= {
    0x81000001  /*  0: li   R01    1 */
  };

  load_program(&spim, program, PROGRAM_SIZE);

  assert(spim.memory[0] == 0x81000001);

  printf("Success!\n");  /* the assertion succeeded */

  return 0;
}
