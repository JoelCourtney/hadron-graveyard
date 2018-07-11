CC=gcc
CFLAGS=-Wall -Wextra

quanta: main.o List.o Number.o Parser.o Executor.o Environment.o
	gcc main.o List.o Number.o Parser.o Executor.o Environment.o -o quanta

speedy:
	gcc -O3 main.c List.c Number.c Parser.c Executor.c Environment.c -o quantaSpeedy

main.o: main.c Quantity.h
	gcc -c main.c
List.o: List.h List.c
	gcc -c List.c
Number.o: Number.h Number.c
	gcc -c Number.c
Parser.o: Parser.h Parser.c
	gcc -c Parser.c
Executor.o: Executor.h Executor.c
	gcc -c Executor.c
Environment.o: Environment.h Environment.c
	gcc -c Environment.c

clean:
	rm -rf main.o List.o Number.o Parser.o Executor.o Environment.o quanta quantaSpeedy
