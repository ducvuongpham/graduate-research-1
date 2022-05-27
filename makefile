CFLAGS = -c -Wall 
CC = gcc -g
LIBS =  -lm 

vpath %.c  src
vpath %.h  src

SRCDIR = src
OBJDIR = obj

all: main

objects = $(addprefix $(OBJDIR)/, main.o menu.o graph.o queue.o stack.o import.o dfs.o bfs.o ccc.o)

main: $(objects)
	$(CC) $(objects) -o main
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *~ obj/*.o obj/*~