#include "push_swap.h"

int order_search(int value, const int *sorted_str)
{
    int i;

    i = 0;
    while (1)
    {
        if (sorted_str[i] == value)
        {
            return (i);
        }
        i++;
    }
}

void	index_stack(t_stack *stack_a, int *str)
{
    t_stack *tmp_list;

    tmp_list = stack_a;
    while (tmp_list)
    {
        tmp_list->order = order_search(tmp_list->value, str);
        tmp_list = tmp_list->next;
    }
}

t_list *frame_init(t_list *frame, int argc, char **argv)
{
    frame->stack_a = create_stack(ft_atoi(argv[argc-1]));
    if(!frame->stack_a)
        return (NULL);
    frame->stack_b = NULL;
    frame->argv = argv;
    return(frame);
}

int main(int argc, char **argv)
{
    t_list *frame;
    t_stack *tmp_list;
    int     *str;
    int     i;

    if (error_handling(argc, argv))
        return(write_error(-1));
    str = mass_create_and_sort(argc, argv);
    if (!str)
        return(0);
    frame = (t_list*)malloc(sizeof(t_list));
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
    print_test(frame->stack_a);
    free(str);
   // free_stack(&frame);
    return(0);
}
