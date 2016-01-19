#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Public test 7 (public07.c)
 *
 * Tests using the operation of encode_instruction() to create some other
 * instructions.
 */

int main() {
  Word word;

  encode_instruction(LW, R06, R00, R00, 64, &word);
  assert(word == 0x76000040);

  encode_instruction(LI, R10, R00, R00, 32, &word);
  assert(word == 0x8a000020);

  encode_instruction(SW, R09, R00, R00, 124, &word);
  assert(word == 0x9900007c);

  encode_instruction(READ, R08, R00, R00, 0, &word);
  assert(word == 0xc8000000);

  encode_instruction(WRITE, R07, R00, R00, 0, &word);
  assert(word == 0xd7000000);

  printf("All assertions succeeded!\n");

  return 0;
}
