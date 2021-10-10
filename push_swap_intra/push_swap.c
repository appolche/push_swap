/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:13:20 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:26:02 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_frame	*frame;
	int		*str;

	if (error_handling(argc, argv) == 1)
		return (write_error(-1));
	str = str_create_and_sort(argc, argv);
	if (!str)
		return (0);
	frame = create_frame(argc, argv, str);
	if (!frame)
		return (0);
	if (frame->stack_size <= 5)
		sort_small_stack(frame);
	else
		radix_sort_big_stack(argc, frame);
	free(str);
	free_frame(&frame);
	return (0);
}
