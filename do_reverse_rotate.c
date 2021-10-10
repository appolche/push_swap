#include "push_swap.h"

void	do_rra(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *head;

        head = (*stack_a)->next;
        tmp = stack_top(*stack_a);
        (*stack_a)->next->prev = NULL;
        (*stack_a)->prev = tmp;
        (*stack_a)->next = NULL;
        tmp->next = *stack_a;
        (*stack_a) = head;
        write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *head;

        head = (*stack_b)->next;
        tmp = stack_top(*stack_b);
        (*stack_b)->next->prev = NULL;
        (*stack_b)->prev = tmp;
        (*stack_b)->next = NULL;
        tmp->next = *stack_b;
        (*stack_b) = head;
        write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(&(*stack_a));
	do_rrb(&(*stack_b));
	write(1, "rrr\n", 4);
}
