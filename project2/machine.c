#include"./machine.h"
#include<stddef.h>
#include<stdio.h>
#include<stdbool.h>
void
print_instruction (Word instruction)
{
  Word opcode = (instruction >> 28) & 0xf;
  Word Register1 = (instruction & 0x0F000000) >> 24;
  Word Register2 = (instruction & 0x00F00000) >> 20;
  Word Register3 = (instruction & 0x000F0000) >> 16;
  Word Address = instruction & 0x0000FFFF;

  if (opcode == HALT)
    printf ("halt\n");
  else if (opcode == ADD)
    {
      printf ("add    R%02i  R%02i  R%02i\n", Register1,
	      Register2, Register3);
    }
  else if (opcode == MUL)
    {
      printf ("mul    R%02i  R%02i  R%02i\n", Register1, Register2,
	      Register3);
    }
  else if (opcode == NEG)
    {
      printf ("neg    R%02i  R%02i\n", Register1, Register2);

    }
  else if (opcode == SHL)
    {
      printf ("shl    R%02i  R%02i  %05i\n", Register1, Register2, Address);
    }
  else if (opcode == AND)
    {
      printf ("and    R%02i  R%02i  R%02i\n", Register1,
	      Register2, Register3);
    }
  else if (opcode == NOT)
    {
      printf ("not    R%02i  R%02i\n", Register1, Register2);
    }
  else if (opcode == LW)
    {
      printf ("lw     R%02i  %05i\n", Register1, Address);
    }
  else if (opcode == LI)
    {
      printf ("li     R%02i  %05i\n", Register1, Address);
    }
  else if (opcode == SW)
    {
      printf ("sw     R%02i  %05i\n", Register1, Address);
    }
  else if (opcode == MOVE)
    {
      printf ("move   R%02i  R%02i\n", Register1, Register2);
    }
  else if (opcode == BNE)
    {
      printf ("bne    R%02i  R%02i  %05i\n", Register1, Register2, Address);
    }
  else if (opcode == READ)
    {
      printf ("read   R%02i\n", Register1);

    }
  else if (opcode == WRITE)
    {
      printf ("write  R%02i\n", Register1);
    }
}

int
disassemble (const Word memory[], int starting_address, int num_words)
{
  Word const *const instruction_ptr = &memory[starting_address / 4];
  int i;
  if (memory == NULL || (starting_address % 4) != 0
      || (starting_address < 0)
      || ((starting_address + num_words * 4) > 49151))
    return -1;
  if (num_words <= 0)
    return 0;
  for (i = 0; i < num_words; i++)
    if (valid_instruction (instruction_ptr[i]))
      {
	printf ("0x%04x: ", 4 * i + starting_address);
	print_instruction (instruction_ptr[i]);
      }
    else
      return i;
  return num_words;
}

int
encode_instruction (unsigned int opcode, unsigned int reg1,
		    unsigned int reg2, unsigned int reg3,
		    unsigned int memory_addr, Word * const instruction)
{
  Word e_instruction = 0;
  if (instruction == NULL)
    return 0;

  e_instruction |= opcode << 28;
  /*use switch to set unused fields to 0 */
  switch (opcode)
    {
    case HALT:
      reg1 = 0, reg2 = 0, reg3 = 0, memory_addr = 0;
      break;

    case ADD:
      memory_addr = 0;
      break;

    case MUL:
      memory_addr = 0;
      break;
    case NEG:
      reg3 = 0, memory_addr = 0;
      break;
    case SHL:
      reg3 = 0;
      break;
    case AND:
      memory_addr = 0;
      break;
    case NOT:
      reg3 = 0, memory_addr = 0;
      break;
    case LW:
      reg2 = 0, reg3 = 0;
      break;
    case LI:
      reg2 = 0, reg3 = 0;
      break;
    case SW:
      reg2 = 0, reg3 = 0;
      break;
    case MOVE:
      reg3 = 0, memory_addr = 0;
      break;
    case BNE:
      reg3 = 0;
      break;
    case READ:
      reg2 = 0, reg3 = 0, memory_addr = 0;
      break;
    case WRITE:
      reg2 = 0, reg3 = 0, memory_addr = 0;
      break;
    }
  e_instruction |= reg1 << 24;
  e_instruction |= reg2 << 20;
  e_instruction |= reg3 << 16;
  e_instruction |= memory_addr;
  if (!valid_instruction (e_instruction))
    return 0;

  *instruction = e_instruction;
  return 1;
}

int
valid_instruction (Word instruction)
{
  Word opcode = (instruction >> 28) & 0x0000000f;
  Word Register1 = (instruction & (0x0f00 << 16)) >> 24;
  Word Register2 = (instruction & (0x00f0 << 16)) >> 20;
  Word Register3 = (instruction & (0x000f << 16)) >> 16;
  Word Address = instruction & (0x0000ffff);

  if (opcode == HALT)
    return true;
  else if ((Register1 == R00) && (opcode != SW)
	   && (opcode != WRITE) && (opcode != BNE))
    return false;
  else if ((opcode == ADD) || (opcode == MUL) || (opcode == AND))
    return (Register1 < 11) && (Register2 < 12) && (Register3 < 12);
  else if ((opcode == NEG) || (opcode == NOT) || (opcode == MOVE))
    return (Register1 < 11) && (Register2 < 12);
  else if ((opcode == BNE))
    return (Register1 < 12) && (Register2 < 12) && (Address < 49152);
  else if ((opcode == LW) || (opcode == SW))
    return (Register1 < 11) && (Address < 49152) && (!(Address % 4));
  else if (opcode == READ)
    return Register1 < 11;
  else if (opcode == WRITE)
    return Register1 < 12;
  else if (opcode == SHL)
    return (Register1 < 11) && (Register2 < 12) && (Address < 32);
  else if (opcode == LI)
    return (Register1 < 11);

  return false;
}
