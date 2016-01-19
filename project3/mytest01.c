#include"./machine.h"
#include"./interpreter.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
Word* mem = malloc(sizeof(Word) * 100);
Machine spim;
int i;
encode_instruction(LI,R08,R03,R04,8,mem);
encode_instruction(LI,R04,R03,R04,0,mem+1);
encode_instruction(LI,R03,R05,R06,1,mem+2);
encode_instruction(HALT,R02,R02,R03,0,mem+3);
encode_instruction(ADD,R02,R02,R03,0,mem+4);
encode_instruction(MUL,R02,R02,R02,0,mem+5);

encode_instruction(MOVE,R02,R02,R03,0,mem+6);
encode_instruction(WRITE,R02,0,0,0,mem+7);
encode_instruction(HALT,0,0,0,0,mem+8);
/*disassemble(mem,0,9);*/
load_program(&spim,mem,9);
run_SPIM_program(&spim,9,&i,1);
reset(&spim);
run_SPIM_program(&spim,9,&i,1);
return 0;
}
