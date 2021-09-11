void	do_sa(t_list **stack_a)
{
	int	tmp;

	if (*stack_a && (*stack_a)->next != *stack_a)
	{
		tmp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = tmp;
	}
		write(1, "sa\n", 3);
}

void	do_sb(t_list **stack_b)
{
	int	tmp;

	if (*stack_b && (*stack_b)->next != *stack_b)
	{
		tmp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = tmp;
	}
		write(1, "sb\n", 3);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	do_sa(*stack_a);
	do_sb(*stack_b);
	write(1, "ss\n", 3);
}