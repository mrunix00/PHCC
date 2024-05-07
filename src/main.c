#include <stdio.h>

#include "include/ast.h"

#include "../autogen/lexer.c"

int
main(int argc, char *argv[])
{
	FILE *input;
	token_list tokens;
	size_t i;

	printf("Portable HolyC Compiler (PHCC) v0.0.0\n");

	if (argc != 2) {
		fprintf(stderr, "[-] No input files!\n");
		return EXIT_FAILURE;
	}

	input = fopen(argv[1], "r");
	tokens = lex(input);

	printf("[");
	for (i = 0; i < tokens.count; i++) {
		switch (tokens.tokens[i].type) {
		case TOKEN_INTEGER:
			printf(" %ld,", tokens.tokens[i].data.i_number);
			break;
		case TOKEN_FLOAT:
			printf(" %f,", tokens.tokens[i].data.f_number);
			break;
		case TOKEN_STRING:
			printf(" \"%s\",", tokens.tokens[i].data.string);
			break;
		default:
			printf(" '%s',", tokens.tokens[i].data.string);
			break;
		}
	}
	printf("\b ]\n");
	return EXIT_SUCCESS;
}
