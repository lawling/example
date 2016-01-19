#include <stdio.h>
#include <assert.h>
#include "machine.h"

/*
 * CMSC 216, Fall 2015, Project #2
 * Secret test 9 (secret09.c)
 *
 * Tests calling encode_instruction() with various invalid parameters and
 * values representing instructions that were not tested in the public
 * tests.
 */

int main() {
  Word word= 0;

  /* invalid opcode */
  assert(encode_instruction(WRITE + 1, R00, R00, R00, 0, &word) == 0);

  /* invalid first register operand- too large */
  assert(encode_instruction(WRITE, R11 + 1, R00, R00, 0, &word) == 0);

  /* invalid second register operand- too large */
  assert(encode_instruction(NEG, R02, R11 + 2, R00, 0, &word) == 0);

  /* invalid third register operand- too large */
  assert(encode_instruction(MUL, R05, R02, R11 + 3, 0, &word) == 0);

  /* invalid memory address- too large */
  assert(encode_instruction(LW, R04, R00, R00, 0xfdc8, &word) == 0);

  /* invalid memory address- not a multiple of 4 */
  assert(encode_instruction(LW, R07, R00, R00, 0x4321, &word) == 0);

  /* invalid destination register of instruction (special register) */
  assert(encode_instruction(LI, R00, R00, R00, 0x0004, &word) == 0);

  /* invalid destination register of instruction (special register) */
  assert(encode_instruction(LW, R11, R00, R00, 0x0004, &word) == 0);

  /* invalid shift amount */
  assert(encode_instruction(SHL, R03, R02, R00, 32, &word) == 0);

  assert(word == 0);  /* ensure it's still unmodified */

  printf("All assertions succeeded!\n");

  return 0;
}
