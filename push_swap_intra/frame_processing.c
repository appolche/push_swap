/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:12:39 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:34:19 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_search(int value, const int *sorted_str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (sorted_str[i] == value)
		{
			return (i + 1);
		}
		i++;
	}
}

void	index_stack(t_stack *stack_a, int *str)
{
	t_stack	*tmp_list;

	tmp_list = stack_a;
	while (tmp_list)
	{
		tmp_list->order = order_search(tmp_list->value, str);
		tmp_list = tmp_list->next;
	}
}

t_frame	*frame_init(t_frame *frame, int argc, char **argv)
{
	int	i;

	i = ft_atoi(argv[argc - 1]);
	frame->stack_a = create_stack(i);
	if (!frame->stack_a)
		return (NULL);
	frame->stack_b = NULL;
	frame->stack_size = argc - 1;
	return (frame);
}

t_frame	*create_frame(int argc, char **argv, int *str)
{
	t_frame	*frame;
	int		i;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!frame)
		return (0);
	frame_init(frame, argc, argv);
	i = argc - 2;
	while (i >= 1)
	{
		ft_push_back(frame->stack_a, ft_atoi(argv[i]));
		i--;
	}
	index_stack(frame->stack_a, str);
	return (frame);
}

void	free_frame(t_frame **frame)
{
	t_stack	*tmp;
	t_stack	*st_a;
	t_stack	*st_b;

	if ((*frame)->stack_a)
	{
		st_a = (*frame)->stack_a;
		while (st_a)
		{
			tmp = (st_a)->next;
			free(st_a);
			st_a = tmp;
		}
	}
	if ((*frame)->stack_b)
	{
		st_b = (*frame)->stack_b;
		while (st_b)
		{
			tmp = (st_b)->next;
			free(st_b);
			st_b = tmp;
		}
	}
	free(*frame);
}
