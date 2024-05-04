#include "token.h"
#include "unity.h"

void
push_token(token_list *list, const char *str, enum Token type)
{
	token_list_push(list, mk_token(str, type, 1, 1));
}

void
push_token_i(token_list *list, const char *str)
{
	token_list_push(list, mk_token_i(str, 1, 1));
}

void
push_token_f(token_list *list, const char *str)
{
	token_list_push(list, mk_token_f(str, 1, 1));
}

void
push_token_s(token_list *list, const char *str)
{
	token_list_push(list, mk_token_s(str, 1, 1));
}

void
compare_token_lists(token_list list1, token_list list2)
{
	size_t i;
	TEST_ASSERT_EQUAL_INT(list1.count, list2.count); /* Compare sizes */
	for (i = 0; i < list1.count; i++) {
		TEST_ASSERT_EQUAL_INT(list1.tokens[i].type,
		    list2.tokens[i].type);
		switch (list1.tokens[i].type) {
		case TOKEN_INTEGER:
			TEST_ASSERT_EQUAL_INT(list1.tokens[i].data.i_number,
			    list2.tokens[i].data.i_number);
			break;
		case TOKEN_FLOAT:
			TEST_ASSERT_EQUAL_FLOAT(list1.tokens[i].data.floating,
			    list2.tokens[i].data.floating);
			break;
		default:
			TEST_ASSERT_EQUAL_STRING(list1.tokens[i].data.string,
			    list2.tokens[i].data.string);
		}
	}
}
