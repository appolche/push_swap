/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:11:47 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:36:33 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **stack_a)
{
	t_stack	*top;
	int		tmp_value;
	int		tmp_order;
	int		stack_size;

	stack_size = find_stack_size(*stack_a);
	if (stack_size >= 2)
	{
		tmp_value = stack_top(*stack_a)->prev->value;
		tmp_order = stack_top(*stack_a)->prev->order;
		top = stack_top(*stack_a);
		top->prev->value = top->value;
		top->prev->order = top->order;
		top->value = tmp_value;
		top->order = tmp_order;
		write(1, "sa\n", 3);
	}
}

void	do_sb(t_stack **stack_b)
{
	t_stack	*top;
	int		tmp_value;
	int		tmp_order;
	int		stack_size;

	stack_size = find_stack_size(*stack_b);
	if (stack_size >= 2)
	{
		tmp_value = stack_top(*stack_b)->prev->value;
		tmp_order = stack_top(*stack_b)->prev->order;
		top = stack_top(*stack_b);
		top->prev->value = top->value;
		top->prev->order = top->order;
		top->value = tmp_value;
		top->order = tmp_order;
		write(1, "sb\n", 3);
	}
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(&(*stack_a));
	do_sb(&(*stack_b));
	write(1, "ss\n", 3);
}
