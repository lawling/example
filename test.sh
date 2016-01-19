#!/bin/bash
for i in `seq 1 9`;
do
	gcc interpreter.o machine.o secret0$i.c
	echo $(./a.out)
         ./a.out |  diff -ub - secret0$i.output
done

for i in `seq 1 9`;
do 
	gcc interpreter.o machine.o secret1$i.c
	echo $(./a.out)
	./a.out | diff -ub - secret1$i.output
done
