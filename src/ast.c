#include <malloc.h>
#include <stdlib.h>

#include "include/ast.h"

ast_node *
mk_ast_bin_op(token op, struct ast_node *left, struct ast_node *right)
{
	ast_node *node;
	ast_bin_op bin_op;
	bin_op.op = op;
	bin_op.left = left;
	bin_op.right = right;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_BIN_OP;
	node->data.bin_op = bin_op;

	return node;
}

ast_node *
mk_ast_block(struct ast_node *statements, size_t count)
{
	ast_node *node;
	ast_block block;
	block.statements = statements;
	block.count = count;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_BLOCK;
	node->data.block = block;

	return node;
}

ast_node *
mk_ast_func_decl(token name, ast_var_decl *args, size_t args_count)
{
	ast_node *node;
	ast_func_decl func_decl;
	func_decl.name = name;
	func_decl.args = args;
	func_decl.args_count = args_count;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_FUNC_DECL;
	node->data.func_decl = func_decl;

	return node;
}

ast_node *
mk_ast_func_def(ast_func_decl decl, ast_block body)
{
	ast_node *node;
	ast_func_def func_def;
	func_def.decl = decl;
	func_def.body = body;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_FUNC_DEF;
	node->data.func_def = func_def;

	return node;
}

ast_node *
mk_ast_if(struct ast_node *condition, struct ast_node *body,
    struct ast_node *else_body)
{
	ast_node *node;
	ast_if if_stmt;
	if_stmt.condition = condition;
	if_stmt.body = body;
	if_stmt.else_body = else_body;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_IF;
	node->data.if_stmt = if_stmt;

	return node;
}

ast_node *
mk_ast_program(struct ast_node *statements, size_t count)
{
	ast_node *node;
	ast_program program;
	program.statements = statements;
	program.count = count;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_PROGRAM;
	node->data.program = program;

	return node;
}

ast_node *
mk_ast_return(struct ast_node *expr)
{
	ast_node *node;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_RETURN;
	node->data.ret = expr;

	return node;
}

ast_node *
mk_ast_type(token type)
{
	ast_node *node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	node->type = AST_TYPE;
	node->data.type = type;

	return node;
}

ast_node *
mk_ast_var_decl(struct ast_node *type, token name)
{
	ast_node *node;
	ast_var_decl var_decl;
	var_decl.type = type;
	var_decl.name = name;

	node = malloc(sizeof(ast_node));
	if (node == NULL) {
		fprintf(stderr, "[-] Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	node->type = AST_VAR_DECL;
	node->data.var_decl = var_decl;

	return node;
}
