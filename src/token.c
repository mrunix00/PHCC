#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "include/token.h"
#include "utils.h"

token
mk_token(const char *str, enum Token type, size_t line, size_t column)
{
	token t;
	t.data.string = safe_malloc(strlen(str));
	strcpy(t.data.string, str);
	t.type = type;
	t.line = line;
	t.column = column;
	return t;
}

token
mk_token_i(const char *str, size_t line, size_t column)
{
	token t;
	t.data.i_number = strtol(str, NULL, 10);
	t.type = TOKEN_INTEGER;
	t.line = line;
	t.column = column;
	return t;
}

token
mk_token_f(const char *str, size_t line, size_t column)
{
	token t;
	t.data.floating = strtod(str, NULL);
	t.type = TOKEN_FLOAT;
	t.line = line;
	t.column = column;
	return t;
}

token
mk_token_s(const char *str, size_t line, size_t column)
{
	token t;
	t.data.string = safe_malloc(strlen(str) - 2);
	memcpy(t.data.string, str + 1, strlen(str) - 2);
	t.data.string[strlen(str) - 2] = '\0';
	t.type = TOKEN_STRING;
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
	list.tokens = (token *)safe_malloc(sizeof(token) * list.size);
	return list;
}

void
token_list_push(token_list *list, token t)
{
	if (list->count == list->size) {
		list->size *= 2;
		list->tokens = safe_realloc(list->tokens, list->size);
	}
	list->tokens[list->count++] = t;
}
