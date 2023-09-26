cmake_minimum_required(VERSION 3.0.0)

project(
    b_tree
    LANGUAGES C
)

add_executable(main main.c BTree.c)