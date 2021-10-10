cmake_minimum_required(VERSION 3.20)
project(push_swap)

set(CMAKE_CXX_STANDARD 98)

add_executable(push_swap 
        list_tools.c 
        push_swap_main.c 
        error_handling.c
        string_processing.c
        do_rotate.c
        do_reverse_rotate.c
        do_swap.c
        do_push.c 
        sort_stack.c 
        frame_processing.c 
        utils.c)