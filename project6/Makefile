CC := gcc
FLAGS := -ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings 
HEADERS := split.h sss.h sss-implementation.h
OBJS := sss.o split.o memory-checking.o
all:public01.x public02.x public03.x public04.x public05.x \
public06.x public07.x public08.x public09.x public10.x 
public01.x: public01.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public01.o $(OBJS) -o public01.x 
public01.o:public01.c $(HEADERS)
	$(CC) $(FLAGS) -c public01.c

public02.x: public02.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public02.o $(OBJS) -o public02.x 
public02.o:public02.c $(HEADERS)
	$(CC) $(FLAGS) -c public02.c

public03.x: public03.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public03.o $(OBJS) -o public03.x 
public03.o:public03.c $(HEADERS)
	$(CC) $(FLAGS) -c public03.c

public04.x: public04.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public04.o $(OBJS) -o public04.x 
public04.o:public04.c $(HEADERS)
	$(CC) $(FLAGS) -c public04.c

public05.x: public05.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public05.o $(OBJS) -o public05.x 
public05.o:public05.c $(HEADERS)
	$(CC) $(FLAGS) -c public05.c

public06.x: public06.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public06.o $(OBJS) -o public06.x 
public06.o:public06.c $(HEADERS)
	$(CC) $(FLAGS) -c public06.c

public07.x: public07.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public07.o $(OBJS) -o public07.x 
public07.o:public07.c $(HEADERS)
	$(CC) $(FLAGS) -c public07.c

public08.x: public08.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public08.o $(OBJS) -o public08.x 
public08.o:public08.c $(HEADERS)
	$(CC) $(FLAGS) -c public08.c

public09.x: public09.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public09.o $(OBJS) -o public09.x 
public09.o:public09.c $(HEADERS)
	$(CC) $(FLAGS) -c public09.c

public10.x: public10.o $(HEADERS) $(OBJS)
	$(CC) $(FLAGS) public10.o $(OBJS) -o public10.x 
public10.o:public10.c $(HEADERS)
	$(CC) $(FLAGS) -c public10.c

sss.o:sss.c $(HEADERS)
	$(CC) $(FLAGS) -c sss.c
clean:
	rm public??.o
	rm public??.x
	rm sss.o
