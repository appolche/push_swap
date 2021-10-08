#include "push_swap.h"

static void		sort_2_elements(t_list *frame)
{
    t_stack *top;

    top = stack_top(frame->stack_a);
    if (top->order > top->prev->order)
        do_sa(&frame->stack_a);
}

static void		sort_3_elements(t_list *frame)
{
    while (frame->stack_a->order < frame->stack_a->next->order)
        do_rra(&frame->stack_a);
    sort_2_elements(frame);
}

static void		sort_4_or_5_elements(t_list *frame)
{
    int stack_size;
    int	median;
    t_stack *top;

    median = frame->stack_size / 2;
    stack_size = frame->stack_size;
    while (stack_size > 3)
    {
        top = stack_top(frame->stack_a);
        if (top->order > median)
            do_ra(&frame->stack_a);
        else
        {
            do_pb(&frame->stack_a, &frame->stack_b);
            stack_size--;
        }
    }
    sort_3_elements(frame);
    while (frame->stack_b)
        do_pa(&frame->stack_a, &frame->stack_b);
    sort_2_elements(frame);
}

void			sort_small_stack(t_list *frame)
{
    if (frame->stack_size == 2)
        sort_2_elements(frame);
    else if (frame->stack_size == 3)
        sort_3_elements(frame);
    else if (frame->stack_size == 4 || frame->stack_size == 5)
        sort_4_or_5_elements(frame);
}