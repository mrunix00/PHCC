project('PHCC', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c89'])
CC = meson.get_compiler('c')
LEX = find_program('flex')

lexer_c = custom_target(
    'lexer.c',
    output : ['lexer.c', 'lexer.h'],
    input : 'include/lexer.l',
    command : [LEX, '-o../autogen/@OUTPUT0@', '--header-file=../autogen/@OUTPUT1@', '@INPUT@', ],
)

SRCS = library('SRCS', 'src/ast.c', 'src/token.c')
LEX = CC.find_library('l', required : true)
PHCC = executable('PHCC', 'src/main.c', link_with : SRCS, dependencies : LEX, install : true)

test('test', PHCC)