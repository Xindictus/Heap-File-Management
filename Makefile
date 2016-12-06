SOURCE = main.c heap.c
OBJS = main.o heap.o
HEADER = heap.h BF.h
OUT = main
CC = gcc
FLAGS = -c -w

all: $(OBJS) 
	$(CC) -g $(OBJS) -L . BF_32.a -o $(OUT)

main.o : main.c
	$(CC) $(FLAGS) main.c

heap.o: heap.c
	$(CC) $(FLAGS) heap.c

build : $(SOURCE)
	$(CC) -o $(OUT) $(SOURCE)

clean :
	rm -f $(OBJS) $(OUT) heap
