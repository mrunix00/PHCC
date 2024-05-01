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
	for (i = 0; i < tokens.count; i++)
		printf(" '%s',", tokens.tokens[i].data.string);
	printf("\b ]\n");
	return EXIT_SUCCESS;
}
