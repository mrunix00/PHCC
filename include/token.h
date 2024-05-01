#ifndef PHCC_TOKEN_H
#define PHCC_TOKEN_H

#include <stdint.h>

enum Token {
	TOKEN_RIGHT_PAREN,
	TOKEN_LEFT_PAREN,
	TOKEN_RIGHT_BRACE,
	TOKEN_LEFT_BRACE,
	TOKEN_RIGHT_BRACKET,
	TOKEN_LEFT_BRACKET,
	TOKEN_INTEGER,
	TOKEN_FLOAT,
	TOKEN_STRING,
	TOKEN_CHAR,
	TOKEN_IDENTIFIER,
	TOKEN_U0,
	TOKEN_U8,
	TOKEN_U16,
	TOKEN_U32,
	TOKEN_U64,
	TOKEN_I8,
	TOKEN_I16,
	TOKEN_I32,
	TOKEN_I64,
	TOKEN_F64,
	TOKEN_RETURN,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_SWITCH,
	TOKEN_WHILE,
	TOKEN_FOR,
	TOKEN_BREAK,
	TOKEN_CONTINUE,
	TOKEN_CLASS
};

typedef struct {
	enum Token type;
	union {
		char *string;
		int64_t i_number;
		uint64_t u_number;
		double floating;
	} data;
	size_t line;
	size_t column;
} token;

typedef struct {
	token *tokens;
	size_t count;
	size_t size;
} token_list;

token mk_token(const char *str, enum Token type, size_t line, size_t column);
token_list mk_token_list(void);
void token_list_push(token_list *, token);
void token_list_free(token_list *);

#endif