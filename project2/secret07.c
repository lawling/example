#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 7 (secret07.c)
 *
 * Tests calling encode_instruction() with various valid parameters and
 * values representing instructions that were not tested in the public
 * tests.
 */

int main() {
  Word word;

  encode_instruction(ADD, R10, R09, R08, 0, &word);
  assert(word == 0x1a980000);

  encode_instruction(MUL, R01, R00, R11, 0, &word);
  assert(word == 0x210b0000);

  encode_instruction(NEG, R03, R03, R00, 0, &word);
  assert(word == 0x33300000);

  encode_instruction(NOT, R10, R10, R00, 0, &word);
  assert(word == 0x6aa00000);

  encode_instruction(READ, R02, R00, R00, 0, &word);
  assert(word == 0xc2000000);

  encode_instruction(READ, R04, R00, R00, 0, &word);
  assert(word == 0xc4000000);

  encode_instruction(READ, R06, R00, R00, 0, &word);
  assert(word == 0xc6000000);

  encode_instruction(WRITE, R03, R00, R00, 0, &word);
  assert(word == 0xd3000000);

  encode_instruction(WRITE, R05, R00, R00, 0, &word);
  assert(word == 0xd5000000);

  printf("All assertions succeeded!\n");

  return 0;
}
