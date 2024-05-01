#include <malloc.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "include/token.h"

token
mk_token(const char *str, enum Token type, size_t line, size_t column)
{
	token t;
	t.data.string = malloc(strlen(str));
	strcpy(t.data.string, str);
	t.type = type;
	t.line = line;
	t.column = column;
	return t;
}

token_list
mk_token_list(void)
{
	token_list list;
	list.size = 1024;
	list.count = 0;
	list.tokens = (token *)malloc(sizeof(token) * list.size);
	if (list.tokens == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return list;
}

void
token_list_push(token_list *list, token t)
{
	token *new;
	if (list->count == list->size) {
		list->size *= 2;
		new = realloc(list->tokens, list->size);
		if (new == NULL) {
			fprintf(stderr, "[-] Memory allocation failed!\n");
			exit(EXIT_FAILURE);
		}
		list->tokens = new;
	}
	list->tokens[list->count++] = t;
}

void
token_list_free(token_list *list)
{
	free(list->tokens);
	memset(list, 0, sizeof(token_list));
}
