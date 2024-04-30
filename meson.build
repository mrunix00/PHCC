project('PHCC', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c89'])

SRCS = library('SRCS', 'src/ast.c')
PHCC = executable('PHCC', 'src/main.c', link_with : SRCS, install : true)

test('test', PHCC)