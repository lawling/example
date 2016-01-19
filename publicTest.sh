#!/bin/bash
for i in `seq 1 9`;
do
	gcc interpreter.o machine.o public0$i.c
#	echo $(./a.out)
         ./a.out |  diff -ub - public0$i.output
done

for i in `seq 0`;
do 
	gcc interpreter.o machine.o public1$i.c
#	echo $(./a.out)
	./a.out | diff -ub - public1$i.output
done
