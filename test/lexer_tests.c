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

int
main(void)
{
	UNITY_BEGIN();
	RUN_TEST(lex_ignore_single_line_comments);
	RUN_TEST(lex_ignore_comment_at_the_end_of_line);
	RUN_TEST(lex_ignore_multi_line_comments);
	return UNITY_END();
}
