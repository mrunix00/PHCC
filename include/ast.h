#ifndef AST_H
#define AST_H

#include "token.h"

enum ast_node_type {
	AST_BIN_OP,
	AST_BLOCK,
	AST_FUNC_DECL,
	AST_FUNC_DEF,
	AST_IF,
	AST_PROGRAM,
	AST_RETURN,
	AST_TYPE,
	AST_VAR_DECL
};

struct ast_node;

typedef struct {
	token op;
	struct ast_node *left;
	struct ast_node *right;
} ast_bin_op;

typedef struct {
	struct ast_node *statements;
	size_t count;
} ast_block;

typedef struct {
	struct ast_node *type;
	token name;
} ast_var_decl;

typedef struct {
	token name;
	ast_var_decl *args;
	size_t args_count;
} ast_func_decl;

typedef struct {
	struct ast_node *type;
	ast_func_decl decl;
	ast_block body;
} ast_func_def;

typedef struct {
	struct ast_node *condition;
	struct ast_node *body;
	struct ast_node *else_body;
} ast_if;

typedef struct {
	struct ast_node *statements;
	size_t count;
} ast_program;

typedef struct {
	enum ast_node_type type;
	union {
		ast_bin_op bin_op;
		ast_block block;
		ast_func_decl func_decl;
		ast_func_def func_def;
		ast_if if_stmt;
		ast_program program;
		struct ast_node *ret;
		token type;
		ast_var_decl var_decl;
	} data;
} ast_node;

ast_node *mk_ast_bin_op(token op, struct ast_node *left,
    struct ast_node *right);
ast_node *mk_ast_block(struct ast_node *stms, size_t count);
ast_node *mk_ast_func_decl(token name, ast_var_decl *args, size_t args_count);
ast_node *mk_ast_func_def(ast_func_decl decl, ast_block body);
ast_node *mk_ast_if(struct ast_node *cond, struct ast_node *body,
    struct ast_node *else_body);
ast_node *mk_ast_program(struct ast_node *stms, size_t count);
ast_node *mk_ast_return(struct ast_node *expr);
ast_node *mk_ast_type(token);
ast_node *mk_ast_var_decl(struct ast_node *type, token name);

#endif
