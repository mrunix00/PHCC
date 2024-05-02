%{
#include "include/token.h"

int line = 1;
int column = 1;
token_list l_token_list;

void
add_token(token t)
{
    token_list_push(&l_token_list, t);
    column += yyleng;
}

%}

%%

[\n]        { line++; column = 1; }
[\t ]+      { column += yyleng; }

F64         { add_token(mk_token(yytext, TOKEN_F64, line, column)); }
I8          { add_token(mk_token(yytext, TOKEN_I8, line, column)); }
I16         { add_token(mk_token(yytext, TOKEN_I16, line, column)); }
I32         { add_token(mk_token(yytext, TOKEN_I32, line, column)); }
I64         { add_token(mk_token(yytext, TOKEN_I64, line, column)); }
U0          { add_token(mk_token(yytext, TOKEN_U0, line, column)); }
U8          { add_token(mk_token(yytext, TOKEN_U8, line, column)); }
U16         { add_token(mk_token(yytext, TOKEN_U16, line, column)); }
U32         { add_token(mk_token(yytext, TOKEN_U32, line, column)); }
U64         { add_token(mk_token(yytext, TOKEN_U64, line, column)); }
[(]         { add_token(mk_token(yytext, TOKEN_LEFT_PAREN, line, column)); }
[)]         { add_token(mk_token(yytext, TOKEN_RIGHT_PAREN, line, column)); }
[{]         { add_token(mk_token(yytext, TOKEN_LEFT_BRACE, line, column)); }
[}]         { add_token(mk_token(yytext, TOKEN_RIGHT_BRACE, line, column)); }
[\[]        { add_token(mk_token(yytext, TOKEN_LEFT_BRACKET, line, column)); }
[\]]        { add_token(mk_token(yytext, TOKEN_RIGHT_BRACKET, line, column)); }
break       { add_token(mk_token(yytext, TOKEN_BREAK, line, column)); }
class       { add_token(mk_token(yytext, TOKEN_CLASS, line, column)); }
continue    { add_token(mk_token(yytext, TOKEN_CONTINUE, line, column)); }
else        { add_token(mk_token(yytext, TOKEN_ELSE, line, column)); }
for         { add_token(mk_token(yytext, TOKEN_FOR, line, column)); }
if          { add_token(mk_token(yytext, TOKEN_IF, line, column)); }
return      { add_token(mk_token(yytext, TOKEN_RETURN, line, column)); }
switch      { add_token(mk_token(yytext, TOKEN_SWITCH, line, column)); }
while       { add_token(mk_token(yytext, TOKEN_WHILE, line, column)); }

[*]         { add_token(mk_token(yytext, TOKEN_PTR, line, column)); }
[,]         { add_token(mk_token(yytext, TOKEN_COMMA, line, column)); }
[;]         { add_token(mk_token(yytext, TOKEN_SEMICOLON, line, column)); }
-?[0-9]+    { add_token(mk_token_i(yytext, line, column)); }
-?[0-9]+\.[0-9]+    { add_token(mk_token_f(yytext, line, column)); }
\"([^\\\"]|\\.)*\"  { add_token(mk_token_s(yytext, line, column)); }
[A-Za-z_][A-Za-z0-9_]+  { add_token(mk_token(yytext, TOKEN_IDENTIFIER, line, column)); }

.|\n        { ECHO; column++; }

%%

token_list
lex(FILE *file) {
    extern FILE *yyin;
    yyin = file;
    l_token_list = mk_token_list();
    yylex();
    return l_token_list;
}
