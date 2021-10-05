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
    return(frame);
}

void radix_sort_big_stack(int argc, t_list *frame)
{
    int size = argc - 1;
    int max_num = size; // the biggest number in a is stack_size - 1
    int max_bits = 0; // how many bits for max_num
    while ((max_num >> max_bits) != 0)
        ++max_bits;
    for (int k = 0 ; k < max_bits ; ++k) // repeat for max_bits times
    {
        for(int j = 0 ; j < size ; ++j)
        {
            int num = stack_top(frame->stack_a)->order; // top number of A
            if (((num >> k) & 1) == 1)
                do_ra(&frame->stack_a);
                // if the (i + 1)-th bit is 1, leave in stack a
            else
            {
                do_pb(&frame->stack_a, &frame->stack_b);
            }
            // otherwise push to stack b
        }
        // put into boxes done
        while (frame->stack_b)
        {
            do_pa(&frame->stack_a, &frame->stack_b); // while stack b is not empty, do pa
        }
        // connect numbers done
    }
}
/*
void	sort_stack_size3(t_stack *stack_a, int *nmoves)
{
    if (stack_a->top->index > stack_a->top->prev->index
        && stack_a->top->index > stack_a->root->index)
        ra(stack_a, nmoves);
    else if (stack_a->root->index < stack_a->top->prev->index)
        rra(stack_a, nmoves);
    if (stack_a->top->index > stack_a->top->prev->index)
        sa(stack_a, nmoves);
}

void	r_sort_stack_size3(t_stack *stack_b, int *nmoves)
{
    if (stack_b->top->index < stack_b->top->prev->index
        && stack_b->top->index < stack_b->root->index)
        rb(stack_b, nmoves);
    else if (stack_b->root->index > stack_b->top->prev->index)
        rrb(stack_b, nmoves);
    if (stack_b->top->index < stack_b->top->prev->index)
        sb(stack_b, nmoves);
}*/

static void		solve_2(t_list *frame)
{
    t_stack *top;

    top = stack_top(frame->stack_a);
    if (top->order > top->prev->order)
        do_sa(&frame->stack_a);
}

static void		solve_3(t_list *frame)
{
    while (frame->stack_a->order < frame->stack_a->next->order)
        do_rra(&frame->stack_a);
    solve_2(frame);
}

static void		solve_4(t_list *frame)
{
    int stack_size;
    int	median;
    t_stack *top;

    median = frame->stack_a->order / 2;
    stack_size = frame->stack_size;
    while (stack_size > 3)
    {
        top = stack_top(frame->stack_a);
        if (top->order >= median)
            do_ra(&frame->stack_a);
        else
        {
            do_pb(&frame->stack_a, &frame->stack_b);
        }
        stack_size--;
        print_test(frame->stack_a);
    }
    solve_3(frame);
}
/*
static void		solve_5(t_frame *frame)
{
    t_stack *stack_a_end;
    t_stack	*tmp;
    int		flag;

    flag = 0;
    stack_a_end = frame->a->prev;
    median(frame, 'a');
    while (flag != 1)
    {
        frame->a == stack_a_end ? flag = 1 : 0;
        if (frame->a->num < MEDIAN)
            do_pb(frame);
        else
            do_ra(frame);
    }
    solve_3(frame);
    tmp = frame->b->next;
    frame->b->num < tmp->num ? do_sb(frame) : 0;
    do_pa(frame);
    do_pa(frame);
}*/

void			solve_5_or_less(t_list *frame)
{
    if (frame->stack_size == 2)
        solve_2(frame);
    else if (frame->stack_size == 3)
        solve_3(frame);
    else if (frame->stack_size == 4)
        solve_4(frame);/*
    else if (frame->stack_size <= 5)
        solve_5(frame);*/
}
/*
void sort_small_stack(t_list *frame)
{
    int	median;

    median = frame->stack_size / 2;
    if (frame->stack_a->order > median)
        do_ra(&frame->stack_a);
    else
        do_pb(&frame->stack_a, &frame->stack_b);

    if (frame->stack_b->size == 3)
        r_sort_stack_size3(frame->stack_b, &frame->nmoves);
    else if (frame->stack_b->size == 2
             && frame->stack_b->top->index < frame->stack_b->root->index)
        do_sb(&frame->stack_b);
    while (frame->stack_b->size > 0)
        do_pa(&frame->stack_a, &frame->stack_b);
}*/

int main(int argc, char **argv)
{
    t_list *frame;
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
    if (frame->stack_size > 5)
        radix_sort_big_stack(argc, frame);
    else
        solve_5_or_less(frame);
    print_test(frame->stack_a);
    print_test(frame->stack_b);
    free(str);
   // free_stack(&frame);
    return(0);
}
