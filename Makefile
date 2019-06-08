.PHONY: all clean run
all: exec
exec: main.o gol.o
	gcc main.o gol.o -o exec
main.o: main.c gol.h
	gcc -c main.c
gol.o: gol.c gol.h
	gcc -c gol.c
run: exec
	./exec
clean: clean
	rm main.o gol.o exec