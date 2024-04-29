project('PHCC', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c89'])

PHCC = executable('PHCC', 'src/main.c', install : true)

test('test', PHCC)