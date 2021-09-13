void	do_ra(t_list **stack_a)
{
    t_list *tmp;

    tmp = *stack_a;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack_a)->prev = tmp;
    tmp->next = *stack_a;
    *stack_a = tmp;
	write(1, "rra\n", 4);
}

void	do_rb(t_list **stack_b)
{
    t_list *tmp;

    tmp = *stack_b;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack_b)->prev = tmp;
    tmp->next = *stack_b;
    *stack_b = tmp;
	write(1, "rrb\n", 4);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	do_rra(*stack_a);
	do_rrb(*stack_b);
	write(1, "rrr\n", 4);
}