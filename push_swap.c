#include "push_swap.h"

void radix_sort_big_stack(int argc, t_list *frame)
{
    int size;
    int max_num; // the biggest number in a is stack_size - 1
    int max_bits; // how many bits for max_num
    int num;
    int k;
    int j;

    size = argc - 1;
    max_num = size;
    max_bits = 0;
    k = 0;
    while ((max_num >> max_bits) != 0)
        ++max_bits;
    while (k < max_bits) // repeat for max_bits times
    {
        j = 0;
        while (j < size)
        {
            num = stack_top(frame->stack_a)->order;
            if (((num >> k) & 1) == 1)
                do_ra(&frame->stack_a);
            else
            {
                do_pb(&frame->stack_a, &frame->stack_b);
            }
            ++j;
        }
        // put into boxes done
        while (frame->stack_b)
        {
            do_pa(&frame->stack_a, &frame->stack_b); // while stack b is not empty, do pa
        }
        // connect numbers done
        ++k;
    }
}

int main(int argc, char **argv)
{
    t_list *frame;
    int     *str;
    int     i;

    if (error_handling(argc, argv))
        return(write_error(-1));
    str = str_create_and_sort(argc, argv);
    if (!str)
        return (0);
    frame = (t_list*) malloc(sizeof(t_list));
    if (!frame)
        return(0);
    frame_init(frame, argc, argv);
    i = argc - 2;
    while (i >= 1)
    {
        ft_push_back(frame->stack_a, ft_atoi(argv[i]));
        i--;
    }
    index_stack(frame->stack_a, str);
    if (frame->stack_size > 5)
        radix_sort_big_stack(argc, frame);
    else
        sort_small_stack(frame);
    print_test(frame->stack_a);
    //print_test(frame->stack_b);
    free(str);
   // free_stack(&frame);
    return(0);
}
