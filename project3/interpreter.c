/****************************
*this file is written by Yuan Liang
*these functions implement the simulation of SPIM machine
****************************/

#include "./machine.h"
#include "./interpreter.h"
#include<stddef.h>
#include<stdio.h>
/*
load a program into machine 
check validty of parameter
*/
int
load_program (Machine * const spim, const Word program[], int program_size)
{
  int i;
  if (spim == NULL || program_size > MAX_MEMORY)
    return 0;

  /*nothing is done for non-positive program size */
  if (program_size <= 0)
    return 1;

  /*copy program to memory */
  for (i = 0; i < program_size; i++)
    {
      spim->memory[i] = program[i];
    }

  /*set program counter to 0 */
  spim->registers[11] = 0;

  return 1;
}

/*
run the machine until max_instr counter
return run instructions in the pointer num_instr
trace_flag for debug purpose
*/
Status
run_SPIM_program (Machine * const spim,
		  int max_instr, int *const num_instr, int trace_flag)
{
  Word instruction;
  Word opcode, immediate, register1, register2, register3;
  int *program_counter = &spim->registers[11];
  int i, *const SPIM_regs = spim->registers;
  /*test validity of arguments*/
  if (spim == NULL || num_instr == NULL)
    return PARAMETER_ERROR;

  if (max_instr <= 0)
    return TIMEOUT;

  if (trace_flag)
    disassemble (spim->memory, *program_counter, max_instr);

  for (i = 0; i < max_instr; i++)
    {
      /*fetch instruction from memory */
      instruction = spim->memory[(*program_counter) / 4];
      if (!valid_instruction (instruction))
	return INVALID_INSTRUCTION;

      /*decode the instruction */
      opcode = (instruction >> 28) & 0xf;
      immediate = instruction & 0xffff;
      register1 = (instruction >> 24) & 0xf;
      register2 = (instruction >> 20) & 0xf;
      register3 = (instruction >> 16) & 0xf;

      /*excute the instruction */
      /*program_counter is incremented or changed in this stage */
      /*validity of instructions is checked in run time */
      switch (opcode)
	{
	case HALT:
	  return HALTED;
	case ADD:
	  (*program_counter) += 4;
	  SPIM_regs[register1] =
	    SPIM_regs[register2] + SPIM_regs[register3];
	  break;
	case MUL:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = SPIM_regs[register2]
	    * SPIM_regs[register3];
	  break;
	case NEG:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = -SPIM_regs[register2];
	  break;
	case SHL:
	  (*program_counter) += 4;
	  if (immediate > 31)
	    return INVALID_INSTRUCTION;
	  SPIM_regs[register1] = SPIM_regs[register2] << immediate;
	  break;
	case AND:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = SPIM_regs[register2]
	    && SPIM_regs[register3];
	  break;
	case NOT:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = !SPIM_regs[register2];
	  break;
	case LW:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = spim->memory[immediate];
	  break;
	case LI:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = immediate;
	  break;
	case SW:
	  (*program_counter) += 4;
	  spim->memory[immediate / 4] = SPIM_regs[register1];
	  break;
	case MOVE:
	  (*program_counter) += 4;
	  SPIM_regs[register1] = SPIM_regs[register2];
	  break;
	case BNE:
	  if (SPIM_regs[register1] == SPIM_regs[register2])
	    (*program_counter) += 4;
	  else
	    {
	      if (immediate % 4 != 0)
		return INVALID_INSTRUCTION;
	      else
		*program_counter = immediate;
	    }
	  break;
	case READ:
	  *program_counter += 4;
	  scanf ("%d", &SPIM_regs[register1]);
	  break;
	case WRITE:
	  *program_counter += 4;
	  printf ("%u\n", SPIM_regs[register1]);
	  break;
	}
      *num_instr = i + 1;
    }
  return TIMEOUT;

}

/*
simply reset the program counter
*/
int
reset (Machine * const spim)
{
  if (spim == NULL)
    return 0;
  /*set program_counter to 0 only */
  /*leave other registers unmodified */
  spim->registers[11] = 0;
  return 1;
}
