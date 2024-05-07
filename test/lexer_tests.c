#include "lexer_test_utils.h"
#include "token.h"
#include "unity.h"

#include "../autogen/lexer.c"

void
setUp(void)
{
}

void
tearDown(void)
{
}

void
lex_ignore_single_line_comments(void)
{
	const char *input = "// This is just a comment";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	compare_token_lists(expected, actual);
}

void
lex_ignore_comment_at_the_end_of_line(void)
{
	const char *input = "U16 Var; // This is just a comment";

	token_list actual = lex_string(input);
	token_list expected = mk_token_list();

	/* Prepare expected list */
	token_list_push(&expected, mk_token("U16", TOKEN_U16, 1, 1));
	token_list_push(&expected, mk_token("Var", TOKEN_IDENTIFIER, 1, 5));
	token_list_push(&expected, mk_token(";", TOKEN_SEMICOLON, 1, 9));

	compare_token_lists(expected, actual);
}

void
lex_ignore_multi_line_comments(void)
{
	const char *input = "//*"
			    "This comment should be ignored"
			    "*//";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	compare_token_lists(expected, actual);
}

void
lex_keywords(void)
{
	const char *input = "U0 U8 U16 U32 U64 I8 I16 I32 I64 F64 "
			    "if switch for while break continue "
			    "return class case default do goto "
			    "throw try catch static public";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	push_token(&expected, "U0", TOKEN_U0);
	push_token(&expected, "U8", TOKEN_U8);
	push_token(&expected, "U16", TOKEN_U16);
	push_token(&expected, "U32", TOKEN_U32);
	push_token(&expected, "U64", TOKEN_U64);
	push_token(&expected, "I8", TOKEN_I8);
	push_token(&expected, "I16", TOKEN_I16);
	push_token(&expected, "I32", TOKEN_I32);
	push_token(&expected, "I64", TOKEN_I64);
	push_token(&expected, "F64", TOKEN_F64);

	push_token(&expected, "if", TOKEN_IF);
	push_token(&expected, "switch", TOKEN_SWITCH);
	push_token(&expected, "for", TOKEN_FOR);
	push_token(&expected, "while", TOKEN_WHILE);
	push_token(&expected, "break", TOKEN_BREAK);
	push_token(&expected, "continue", TOKEN_CONTINUE);

	push_token(&expected, "return", TOKEN_RETURN);
	push_token(&expected, "class", TOKEN_CLASS);
	push_token(&expected, "case", TOKEN_CASE);
	push_token(&expected, "default", TOKEN_DEFAULT);
	push_token(&expected, "do", TOKEN_DO);
	push_token(&expected, "goto", TOKEN_GOTO);

	push_token(&expected, "throw", TOKEN_THROW);
	push_token(&expected, "try", TOKEN_TRY);
	push_token(&expected, "catch", TOKEN_CATCH);
	push_token(&expected, "static", TOKEN_STATIC);
	push_token(&expected, "public", TOKEN_PUBLIC);

	compare_token_lists(expected, actual);
}

void
lex_punctuation(void)
{
	const char *input = "{}()[];,";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	push_token(&expected, "{", TOKEN_LEFT_BRACE);
	push_token(&expected, "}", TOKEN_RIGHT_BRACE);
	push_token(&expected, "(", TOKEN_LEFT_PAREN);
	push_token(&expected, ")", TOKEN_RIGHT_PAREN);
	push_token(&expected, "[", TOKEN_LEFT_BRACKET);
	push_token(&expected, "]", TOKEN_RIGHT_BRACKET);
	push_token(&expected, ";", TOKEN_SEMICOLON);
	push_token(&expected, ",", TOKEN_COMMA);

	compare_token_lists(expected, actual);
}

void
lex_operators(void)
{
	const char *input = "= + - * / % ! && ||"
			    "+= -= *= /= %= ++ --"
			    "== != < > <= >="
			    ">> << >>= <<= & | ^ ~"
			    "&= |= ^= ~=";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	push_token(&expected, "=", TOKEN_OP_ASSIGN);
	push_token(&expected, "+", TOKEN_OP_ADD);
	push_token(&expected, "-", TOKEN_OP_SUB);
	push_token(&expected, "*", TOKEN_OP_MUL);
	push_token(&expected, "/", TOKEN_OP_DIV);
	push_token(&expected, "%", TOKEN_OP_MOD);
	push_token(&expected, "!", TOKEN_OP_NOT);
	push_token(&expected, "&&", TOKEN_OP_AND);
	push_token(&expected, "||", TOKEN_OP_OR);

	push_token(&expected, "+=", TOKEN_OP_ADD_ASSIGN);
	push_token(&expected, "-=", TOKEN_OP_SUB_ASSIGN);
	push_token(&expected, "*=", TOKEN_OP_MUL_ASSIGN);
	push_token(&expected, "/=", TOKEN_OP_DIV_ASSIGN);
	push_token(&expected, "%=", TOKEN_OP_MOD_ASSIGN);
	push_token(&expected, "++", TOKEN_OP_INC);
	push_token(&expected, "--", TOKEN_OP_DEC);

	push_token(&expected, "==", TOKEN_OP_EQ);
	push_token(&expected, "!=", TOKEN_OP_NEQ);
	push_token(&expected, "<", TOKEN_OP_LT);
	push_token(&expected, ">", TOKEN_OP_GT);
	push_token(&expected, "<=", TOKEN_OP_LTE);
	push_token(&expected, ">=", TOKEN_OP_GTE);

	push_token(&expected, ">>", TOKEN_OP_RSHIFT);
	push_token(&expected, "<<", TOKEN_OP_LSHIFT);
	push_token(&expected, ">>=", TOKEN_OP_RSHIFT_ASSIGN);
	push_token(&expected, "<<=", TOKEN_OP_LSHIFT_ASSIGN);
	push_token(&expected, "&", TOKEN_OP_BIT_AND);
	push_token(&expected, "|", TOKEN_OP_BIT_OR);
	push_token(&expected, "^", TOKEN_OP_BIT_XOR);
	push_token(&expected, "~", TOKEN_OP_BIT_NOT);

	push_token(&expected, "&=", TOKEN_OP_BIT_AND_ASSIGN);
	push_token(&expected, "|=", TOKEN_OP_BIT_OR_ASSIGN);
	push_token(&expected, "^=", TOKEN_OP_BIT_XOR_ASSIGN);
	push_token(&expected, "~=", TOKEN_OP_BIT_NOT_ASSIGN);

	compare_token_lists(expected, actual);
}

void
lex_identifiers(void)
{
	const char *input = "FirstVar secondVar third_var "
			    "_forth_var FIFTH_VAR LastVar6";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	push_token(&expected, "FirstVar", TOKEN_IDENTIFIER);
	push_token(&expected, "secondVar", TOKEN_IDENTIFIER);
	push_token(&expected, "third_var", TOKEN_IDENTIFIER);
	push_token(&expected, "_forth_var", TOKEN_IDENTIFIER);
	push_token(&expected, "FIFTH_VAR", TOKEN_IDENTIFIER);
	push_token(&expected, "LastVar6", TOKEN_IDENTIFIER);

	compare_token_lists(expected, actual);
}

void
lex_immediate_values(void)
{
	const char *input = "12 +24 -36 3.1415 +9.81 -273.15"
			    "\"Hello World\"";

	token_list expected = mk_token_list();
	token_list actual = lex_string(input);

	push_token_u(&expected, "12");
	push_token_u(&expected, "24");
	push_token_i(&expected, "-36");
	push_token_f(&expected, "3.1415");
	push_token_f(&expected, "9.81");
	push_token_f(&expected, "-273.15");
	push_token_s(&expected, "\"Hello World\"");

	compare_token_lists(expected, actual);
}

int
main(void)
{
	UNITY_BEGIN();
	RUN_TEST(lex_ignore_single_line_comments);
	RUN_TEST(lex_ignore_comment_at_the_end_of_line);
	RUN_TEST(lex_ignore_multi_line_comments);
	RUN_TEST(lex_keywords);
	RUN_TEST(lex_punctuation);
	RUN_TEST(lex_operators);
	RUN_TEST(lex_identifiers);
	RUN_TEST(lex_immediate_values);
	return UNITY_END();
}
