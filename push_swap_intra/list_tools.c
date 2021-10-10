/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:12:57 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:27:59 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->order = 0;
	return (node);
}

void	ft_push_back(t_stack *stack, int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	while (stack->next)
	{
		stack = stack->next;
	}
	stack->next = node;
	node->prev = stack;
	node->next = NULL;
	node->order = -1;
	node->value = value;
}

void	ft_pop_back(t_stack **stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack_top(*stack);
	if (tmp_stack->prev)
		tmp_stack->prev->next = NULL;
	else
		*stack = NULL;
	free(tmp_stack);
}

t_stack	*stack_top(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

int	find_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	tmp = stack;
	size = 0;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
