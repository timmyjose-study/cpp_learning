chapter1_inc_dir = include_directories('include')

rationals = executable('rationals', 'src/rationals.cpp', include_directories: chapter1_inc_dir)
birds = executable('birds', 'src/birds.cpp', include_directories: chapter1_inc_dir)

test('rationals', rationals)
test('birds', birds)