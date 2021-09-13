void	do_ra(t_list **stack_a)
{
    t_list *tmp;
    t_list *head;

    head = (*stack_a)->next;
    tmp = *stack_a;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    (*stack_a)->next->prev = NULL;
    (*stack_a)->prev = tmp;
    (*stack_a)->next = NULL;
    tmp->next = *stack_a;
    (*stack_a) = head;
	write(1, "rra\n", 4);
}

void	do_rb(t_list **stack_b)
{
    t_list *tmp;
    t_list *head;

    head = (*stack_b)->next;
    tmp = *stack_b;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    (*stack_b)->next->prev = NULL;
    (*stack_b)->prev = tmp;
    (*stack_b)->next = NULL;
    tmp->next = *stack_b;
    (*stack_b) = head;
    write(1, "rb\n", 3);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	do_ra(&(*stack_a));
	do_rb(&(*stack_b));
	write(1, "rr\n", 3);
}