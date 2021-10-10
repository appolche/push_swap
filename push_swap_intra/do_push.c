/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:08:57 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:38:09 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_stack_a;
	t_stack	*top_stack_b;
	int		tmp_value;
	int		tmp_order;

	if (*stack_b)
	{
		top_stack_b = stack_top(*stack_b);
		tmp_value = top_stack_b->value;
		tmp_order = top_stack_b->order;
		ft_pop_back(&(*stack_b));
		if (*stack_a)
			ft_push_back(*stack_a, tmp_value);
		else
			*stack_a = create_stack(tmp_value);
		top_stack_a = stack_top(*stack_a);
		top_stack_a->order = tmp_order;
		write(1, "pa\n", 3);
	}
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_stack_a;
	t_stack	*top_stack_b;
	int		tmp_value;
	int		tmp_order;

	if (*stack_a)
	{
		top_stack_a = stack_top(*stack_a);
		tmp_value = top_stack_a->value;
		tmp_order = top_stack_a->order;
		ft_pop_back(&(*stack_a));
		if (*stack_b)
			ft_push_back(*stack_b, tmp_value);
		else
			*stack_b = create_stack(tmp_value);
		top_stack_b = stack_top(*stack_b);
		top_stack_b->order = tmp_order;
		write(1, "pb\n", 3);
	}
}
