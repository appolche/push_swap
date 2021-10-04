# include "push_swap.h"

void	do_ra(t_stack **stack_a)
{
    t_stack *tmp;

    tmp = stack_top(*stack_a);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack_a)->prev = tmp;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "ra\n", 3);
}

void	do_rb(t_stack **stack_b)
{
    t_stack *tmp;

    tmp = stack_top(*stack_b);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack_b)->prev = tmp;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "rb\n", 3);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(&(*stack_a));
	do_rb(&(*stack_b));
	write(1, "rr\n", 3);
}