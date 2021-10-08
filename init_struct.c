#include "push_swap.h"

int order_search(int value, const int *sorted_str)
{
    int i;

    i = 0;
    while (1)
    {
        if (sorted_str[i] == value)
        {
            return (i + 1);
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
    frame->stack_size = argc - 1;
    return (frame);
}
