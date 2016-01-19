
for i in `seq 1 9`;
do
	gcc  machine.c secret0$i.c
	 ./a.out | diff -ub - secret0$i.output 
done

for i in `seq 1 9`;
do
	gcc  machine.c secret1$i.c
	 ./a.out | diff -ub - secret1$i.output 
done
