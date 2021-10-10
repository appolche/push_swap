#include "push_swap.h"

int main(int argc, char **argv)
{
    t_frame *frame;
    int     *str;

    if (error_handling(argc, argv) == 1)
        return(write_error(-1));
    str = str_create_and_sort(argc, argv);
    if (!str)
        return (0);
    frame = create_frame(argc, argv, str);
    if (!frame)
        return (0);
    if (frame->stack_size <= 5)
        sort_small_stack(frame);
    else
        radix_sort_big_stack(argc, frame);
    //print_test(frame->stack_a);
    //print_test(frame->stack_b);
    free(str);
    free_frame(&frame);
    return(0);
}
