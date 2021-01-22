cmake_minimum_required(VERSION 3.10)

project(brainfuckc LANGUAGES C)

file(GLOB SRC_DIR "*.h" "*.c")

source_group("" FILES SRC_DIR)

add_executable(brainfuckc list_node.h interpreter.h brainfuckc.c)
add_executable(list_node_test list_node.h list_node_test.c)
add_executable(interpreter_test list_node.h interpreter_test.c)

file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})