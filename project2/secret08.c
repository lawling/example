#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 8 (secret08.c)
 *
 * Tests calling encode_instruction() with more valid parameters and values
 * representing instructions that were not tested in the public tests.
 */

int main() {
  Word word;

  encode_instruction(WRITE, R07, R00, R00, 0, &word);
  assert(word == 0xd7000000);

  encode_instruction(SHL, R01, R02, R00, 30, &word);
  assert(word == 0x4120001e);

  encode_instruction(SHL, R02, R01, R00, 0, &word);
  assert(word == 0x42100000);

  encode_instruction(BNE, R05, R00, R00, 0x2f58, &word);
  assert(word == 0xb5002f58);

  encode_instruction(BNE, R04, R11, R00, 0x2bcc, &word);
  assert(word == 0xb4b02bcc);

  encode_instruction(LW, R07, R00, R00, 0xa000, &word);
  assert(word == 0x7700a000);

  encode_instruction(LI, R09, R00, R00, 0xbaa8, &word);
  assert(word == 0x8900baa8);

  encode_instruction(LI, R08, R00, R00, 0xaaa4, &word);
  assert(word == 0x8800aaa4);

  printf("All assertions succeeded!\n");

  return 0;
}
