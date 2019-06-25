CC = gcc $(CFLAGS)
CFLAGS = -march=native -Wall -Wextra -std=c99

.PHONY: all debug release clean run

all: debug

debug: CFLAGS += -g -O0
debug: exec

release: CFLAGS += -O3
release: exec

exec: main.o gol.o
	$(CC) main.o gol.o -o exec
main.o: main.c gol.h
	$(CC) -c main.c
gol.o: gol.c gol.h
	$(CC) -c gol.c
run: exec
	./exec
clean: clean
	rm main.o gol.o exec