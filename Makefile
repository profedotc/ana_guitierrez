CC = gcc $(CFLAGS)
CFLAGS = -march=native -Wall -Wextra -std=c99

.PHONY: all debug release clean run test valgrind

all: debug

debug: CFLAGS += -g -O0
debug: exec

release: CFLAGS += -O3
release: exec

test: CFLAGS += -g -O0
test: mem_test valgrind

exec: main.o gol.o
	$(CC) main.o gol.o -o exec
main.o: main.c gol.h
	$(CC) -c main.c
gol.o: gol.c gol.h
	$(CC) -c gol.c
run: exec
	./exec
mem_test: mem_test.o gol.o
	$(CC) mem_test.o gol.o -o mem_test
mem_test.o: mem_test.c gol.h
	$(CC) -c mem_test.c
clean: clean
	rm *.o exec mem_test
valgrind: mem_test
	valgrind --leak-check=full --track-origins=yes ./mem_test