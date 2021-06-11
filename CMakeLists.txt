cmake_minimum_required(VERSION 3.10)

project(brainfuckc LANGUAGES C)

add_executable(bfc list_node.h interpreter.h bfc.c)
add_executable(list_node_test list_node.h list_node_test.c)
add_executable(interpreter_test list_node.h interpreter_test.c)