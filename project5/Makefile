all: public01.x public02.x public03.x public04.x public05.x public06.x\
public07.x public08.x public09.x public10.x
CC:=gcc
FLAGS:= -ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings
OBJS:=graph.o 
HEADERS:= graph.h graph-implementation.h  

public01.x:public01.o $(OBJS) $(HEADERS) memory-checking.h memory-checking.o
	$(CC) public01.o $(FLAGS) $(OBJS) memory-checking.o -o public01.x
public01.o:public01.c $(HEADERS) memory-checking.h
	$(CC) $(FLAGS) -c public01.c

public02.x:public02.o $(OBJS) $(HEADERS) memory-checking.h memory-checking.o
	$(CC) public02.o $(FLAGS) $(OBJS) memory-checking.o  -o public02.x
public02.o:public02.c $(HEADERS) memory-checking.h
	$(CC) $(FLAGS) -c public02.c

public03.x:public03.o $(OBJS) $(HEADERS) 
	$(CC) public03.o $(FLAGS) $(OBJS) -o public03.x
public03.o:public03.c $(HEADERS) 
	$(CC) $(FLAGS) -c public03.c

public04.x:public04.o $(OBJS) $(HEADERS) memory-checking.h memory-checking.o
	$(CC)  public04.o $(FLAGS) $(OBJS) memory-checking.o -o public04.x
public04.o:public04.c $(HEADERS) memory-checking.h
	$(CC) $(FLAGS) -c public04.c

public05.x:public05.o $(OBJS) $(HEADERS)
	$(CC) public05.o $(OBJS) $(FLAGS) -o public05.x
public05.o:public05.c $(HEADERS)
	$(CC) $(FLAGS) -c public05.c

public06.x:public06.o $(OBJS) $(HEADERS)
	$(CC) public06.o $(FLAGS) $(OBJS) -o public06.x
public06.o:public06.c $(HEADERS)
	$(CC) $(FLAGS) -c public06.c

public07.x:public07.o $(OBJS) $(HEADERS)
	$(CC) public07.o $(OBJS) $(FLAGS) -o public07.x
public07.o:public07.c $(HEADERS) 
	$(CC) $(FLAGS)  -c public07.c

public08.x:public08.o $(OBJS) $(HEADERS)
	$(CC) public08.o $(OBJS) $(FLAGS) -o public08.x
public08.o:public08.c $(HEADERS)
	$(CC) $(FLAGS) -c public08.c

public09.x:public09.o $(OBJS) $(HEADERS)
	$(CC) public09.o $(FLAGS) $(OBJS) -o public09.x
public09.o:public09.c $(HEADERS)
	$(CC) $(FLAGS) -c public09.c

public10.x:public10.o $(OBJS) $(HEADERS) name-list-to-string.o name-list-to-string.h memory-checking.h memory-checking.o
	$(CC) public10.o $(FLAGS) $(OBJS) memory-checking.o name-list-to-string.o -o public10.x
public10.o:public10.c $(HEADERS) name-list-to-string.h memory-checking.h
	$(CC) $(FLAGS) -c public10.c

graph.o:graph.c graph.h graph-implementation.h
	$(CC) $(FLAGS) -c graph.c
name-list-to-string.o:name-list-to-string.c
	$(CC) $(FLAGS) -c name-list-to-string.c


clean:
	rm *.x
	rm public??.o
	rm graph.o
	rm name-list-to-string.o
