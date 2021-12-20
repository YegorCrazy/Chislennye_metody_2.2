.PHONY: all clean again

all: main

main.o: main.c
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -c main.c -o main.o -lm

diff_eq.o: diff_eq.c
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -c diff_eq.c -o diff_eq.o -lm
	
matrix.o: matrix.c
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -c matrix.c -o matrix.o -lm

main: main.o diff_eq.o matrix.o
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak diff_eq.o matrix.o main.o -o main -lm

clean:
	rm -rf main *.o

again:
	make clean
	make all
