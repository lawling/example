#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 6 (public06.c)
 *
 * Tests using the operation of encode_instruction() to create various
 * instructions.
 */

int main() {
  Word word;

  encode_instruction(ADD, R02, R01, R00, 0, &word);
  assert(word == 0x12100000);

  encode_instruction(MUL, R05, R04, R03, 0, &word);
  assert(word == 0x25430000);

  encode_instruction(AND, R08, R07, R06, 0, &word);
  assert(word == 0x58760000);

  encode_instruction(NEG, R09, R10, R00, 0, &word);
  assert(word == 0x39a00000);

  encode_instruction(NOT, R09, R11, R00, 0, &word);
  assert(word == 0x69b00000);

  encode_instruction(MOVE, R07, R08, R00, 0, &word);
  assert(word == 0xa7800000);

  encode_instruction(HALT, R00, R00, R00, 0, &word);
  assert(word == 0x00000000);

  printf("All assertions succeeded!\n");

  return 0;
}
