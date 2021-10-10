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

t_frame *frame_init(t_frame *frame, int argc, char **argv)
{
    frame->stack_a = create_stack(ft_atoi(argv[argc-1]));
    if(!frame->stack_a)
        return (NULL);
    frame->stack_b = NULL;
    frame->stack_size = argc - 1;
    return (frame);
}

t_frame *create_frame(int argc, char **argv, int *str)
{
    t_frame *frame;
    int     i;

    frame = (t_frame*) malloc(sizeof(t_frame));
    if (!frame)
        return (0);
    frame_init(frame, argc, argv);
    i = argc - 2;
    while (i >= 1)
    {
        ft_push_back(frame->stack_a, ft_atoi(argv[i]));
        i--;
    }
    index_stack(frame->stack_a, str);
    return (frame);
}
