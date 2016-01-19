CC:=gcc 
FLAGS:=-ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings 

all: public01.x public02.x public03.x public04.x public05.x public06.x public07.x public08.x public09.x public10.x 

public01.x:public01.o graph.h graph.o graph-implementation.h
	$(CC) public01.o graph.o $(FLAGS) -o public01.x
public01.o:public01.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c public01.c

public02.x:public02.o graph.h graph.o graph-implementation.h
	$(CC) public02.o graph.o $(FLAGS) -o public02.x
public02.o:public02.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c public02.c

public03.x:public03.o graph.h graph.o graph-implementation.h
	$(CC) public03.o graph.o $(FLAGS) -o public03.x
public03.o:public03.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c public03.c

public04.x:public04.o graph.h graph.o graph-implementation.h
	$(CC) public04.o graph.o $(FLAGS) -o public04.x
public04.o:public04.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c public04.c

public05.x:public05.o graph.h graph.o graph-implementation.h
	$(CC) public05.o graph.o $(FLAGS) -o public05.x
public05.o:public05.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c public05.c

public06.x:public06.o graph.h graph.o graph-implementation.h 
	$(CC) public06.o graph.o $(FLAGS) -o public06.x 
public06.o:public06.c graph.h graph-implementation.h 
	$(CC) $(FLAGS) -c public06.c 

public07.x:public07.o graph.h graph.o graph-implementation.h 
	$(CC) public07.o graph.o $(FLAGS) -o public07.x 
public07.o:public07.c graph.h graph-implementation.h 
	$(CC) $(FLAGS) -c public07.c 

public08.x:public08.o graph.h graph.o graph-implementation.h 
	$(CC) public08.o graph.o $(FLAGS) -o public08.x 
public08.o:public08.c graph.h graph-implementation.h 
	$(CC) $(FLAGS) -c public08.c 

public09.x:public09.o graph.h graph.o graph-implementation.h 
	$(CC) public09.o graph.o $(FLAGS) -o public09.x 
public09.o:public09.c graph.h graph-implementation.h 
	$(CC) $(FLAGS) -c public09.c

public10.x:public10.o graph.h graph.o graph-implementation.h 
	$(CC) public10.o graph.o $(FLAGS) -o public10.x 
public10.o:public10.c graph.h graph-implementation.h 
	$(CC) $(FLAGS) -c public10.c

graph.o:graph.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c graph.c
clean:
	rm *.o 
	rm *.x
