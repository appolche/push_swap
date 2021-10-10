/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:14:41 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:18:30 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_elements(t_frame *frame)
{
	t_stack	*top;

	top = stack_top(frame->stack_a);
	if (top->order > top->prev->order)
		do_sa(&frame->stack_a);
}

void	sort_3_elements(t_frame *frame)
{
	while (frame->stack_a->order < frame->stack_a->next->order)
		do_rra(&frame->stack_a);
	sort_2_elements(frame);
}

void	sort_4_or_5_elements(t_frame *frame)
{
	int		stack_size;
	int		median;
	t_stack	*top;

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

void	sort_small_stack(t_frame *frame)
{
	if (frame->stack_size == 2)
		sort_2_elements(frame);
	else if (frame->stack_size == 3)
		sort_3_elements(frame);
	else if (frame->stack_size == 4 || frame->stack_size == 5)
		sort_4_or_5_elements(frame);
}

void	radix_sort_big_stack(int argc, t_frame *frame)
{
	int	stack_size;
	int	top_order;
	int	max_bits;
	int	k;
	int	j;

	stack_size = argc - 1;
	max_bits = 0;
	k = 0;
	while ((stack_size >> max_bits) != 0)
		++max_bits;
	stack_size = argc - 1;
	while (k < max_bits)
	{
		j = 0;
		while (j < stack_size)
		{
			top_order = stack_top(frame->stack_a)->order;
			if (((top_order >> k) & 1) == 1)
				do_ra(&frame->stack_a);
			else
				do_pb(&frame->stack_a, &frame->stack_b);
			++j;
		}
		while (frame->stack_b)
			do_pa(&frame->stack_a, &frame->stack_b);
		++k;
	}
}
