void do_pa(t_list **stack_a, t_list **stack_b)
{
    int tmp;

    if (*stack_b)
    {
        tmp = (*stack_b)->value;
        *stack_b = ft_pop_front(*stack_b);
        *stack_a = ft_push_front(*stack_a, tmp);
    }
    write(1, "pa\n", 3);
}

void do_pb(t_list **stack_a, t_list **stack_b)
{
    int tmp;

    if (*stack_a)
    {
        tmp = (*stack_a)->value;
        *stack_a = ft_pop_front(*stack_a);
        *stack_b = ft_push_front(*stack_b, tmp);
    }
    write(1, "pb\n", 3);
}