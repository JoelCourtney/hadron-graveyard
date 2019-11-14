#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Quantity.h"
#include "Number.h"
#include "Parser.h"
#include "Executor.h"
#include "Environment.h"

#define BUFFER_SIZE 50

int main(int argc, char** argv) {
       /* FILE* inputFile;*/
	/*if (argc == 2) {*/
		/*if (access(argv[1], R_OK) == -1) {*/
			/*printf("Input file does not exist, or cannot be read.\n");*/
			/*return -1;*/
	       /* }*/
		/*inputFile = fopen(argv[1],"r");*/
	/*} else {*/
		/*inputFile = stdin;*/
	/*}*/
	/*char* input = calloc(1,1);*/
	/*char buffer[BUFFER_SIZE];*/
	/*if (argc == 1) {*/
		/*printf("Welcome to Quanta Pre-Alpha 1.0.\nIts basically a glorified calculator that does your Physics homework for you.\n\n>> ");*/
	/*}*/
	/*while (fgets(buffer, BUFFER_SIZE, inputFile)) {*/
		/*input = realloc(input, strlen(input) + 1 + strlen(buffer));*/
		/*strcat(input, buffer);*/
		/*if (strchr(input,'\n')) {*/
			/*execLine(parseLine(input));*/
			/*free(input);*/
			/*input = calloc(1,1);*/
			/*if (argc == 1) {*/
				/*printf(">> ");*/
			/*}*/
		/*}*/
	/*}*/
	pushNewScope(false);
	Number n = (Number){5,4,3};
	setVariable("x",&n,N);
	pushNewScope(false);
	Variable* v = getVariable("x");
	printNumber(*((Number*)(v->data)));
}
