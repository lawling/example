#include "./machine.h"
#include "./interpreter.h"
#include<stddef.h>
#include<stdio.h>
int load_program(Machine * const spim, const Word program[],
	int program_size){
    int i;
    if(spim == NULL || program_size > MAX_MEMORY)
	return 0;

    if(program_size <= 0)
	return 1;/*nothing is done*/

    for(i = 0; i < program_size;i++){
	spim->memory[i] = program[i];
    }
    spim->registers[11] = 0;

    return 1;
}
Status run_SPIM_program(Machine* const spim, int max_instr,
	int * const num_instr,int trace_flag){
    Word instruction;
    Word opcode,immediate,register1,register2,register3;
    int * program_counter = &spim->registers[11];
    int i,* const SPIM_regs = spim->registers;

    if(spim == NULL || num_instr == NULL)
	return PARAMETER_ERROR;

    if(max_instr <= 0)
	return TIMEOUT;

    for(i = 0; i < max_instr; i++){
	instruction = spim->memory[(*program_counter)/4];  
        if(!valid_instruction(instruction))
             return INVALID_INSTRUCTION;           

	opcode = (instruction>>28) & 0xf;
	immediate = instruction & 0xffff;
	register1 = (instruction>>24) & 0xf;
	register2 = (instruction>>20) & 0xf;
	register3 = (instruction>>16) & 0xf;

	switch(opcode){
	    case HALT:
                return HALTED;
	    case ADD:
		(*program_counter)+=4;
		SPIM_regs[register1] = SPIM_regs[register2] + SPIM_regs[register3];
		break;
	    case MUL:
		(*program_counter)+=4;
		SPIM_regs[register1] = SPIM_regs[register2] * SPIM_regs[register3];
		break;
	    case NEG:
		(*program_counter)+=4;
		SPIM_regs[register1] = -SPIM_regs[register2];
		break;
	    case SHL:
		(*program_counter)+=4;
                if(immediate > 31)
                    return INVALID_INSTRUCTION;
		SPIM_regs[register1] = SPIM_regs[register2]<<immediate;
		break;
	    case AND:
		(*program_counter)+=4;
		SPIM_regs[register1] = SPIM_regs[register2]
		    && SPIM_regs[register3];
		break;
	    case NOT:
		(*program_counter)+=4;
		SPIM_regs[register1] = !SPIM_regs[register2];
		break;
	    case LW:
		(*program_counter)+=4;
		SPIM_regs[register1] = spim->memory[immediate];
		break;
	    case LI:
		(*program_counter)+=4;
		SPIM_regs[register1] = immediate;
		break;
	    case SW:
		(*program_counter)+=4;
		spim->memory[immediate/4] = SPIM_regs[register1];
		break;
	    case MOVE:
		(*program_counter)+=4;
		SPIM_regs[register1] = SPIM_regs[register2];
		break;
	    case BNE:
                 if(SPIM_regs[register1] == SPIM_regs[register2])
		    (*program_counter)+=4;
                  else (*program_counter) = immediate;
		break;
	    case READ:
		(*program_counter)+=4;
		scanf("%d",&SPIM_regs[register1]);
		break;
	    case WRITE:
		(*program_counter)+=4;
		printf("%u\n",SPIM_regs[register1]);
		break;
	}
        *num_instr = i+1;
    } 
return 1;

}
int reset(Machine* const spim){
    int i;
    if(spim == NULL)
	return 0;

    for(i = 0; i < NUM_REGISTERS; i++)
	spim->registers[i] = 0;
    return 1;
}
