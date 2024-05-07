project(
    'PHCC', 'c',
    version : '1.0.0',
    default_options : ['warning_level=3', 'c_std=c89'])
CC = meson.get_compiler('c')
LEX_PROGRAM = find_program('flex')

LEXER_C = custom_target(
    'lexer.c',
    build_by_default : true,
    output : ['lexer.c', 'lexer.h'],
    input : 'include/lexer.l',
    command : [LEX_PROGRAM, '-o../autogen/@OUTPUT0@', '--header-file=../autogen/@OUTPUT1@', '@INPUT@', ],
)

SRCS = library('SRCS', 'src/ast.c', 'src/token.c', 'src/utils.c')
LEX = CC.find_library('l', required : true)
PHCC = executable(
    'PHCC',
    'src/main.c',
    link_with : SRCS,
    dependencies : LEX,
    install : true
)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

lexer_tests = executable(
    'lexer_tests',
    sources : [files(['test' / 'lexer_tests.c'])],
    link_with : SRCS,
    include_directories : [include_directories('include')],
    dependencies : [unity_dependency, LEX],
)

test('lexer_tests', lexer_tests)