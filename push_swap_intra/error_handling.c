/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:12:08 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:35:32 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(int i)
{
	write(2, "Error\n", 6);
	return (i);
}

int	contain_duplicates(int argc, char **argv)
{
	int	j;
	int	k;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = 1;
		k = 0;
		while (argv[i])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				k++;
			i++;
		}
		if (k >= 2)
			return (1);
		j++;
	}
	return (0);
}

int	contain_max_min_int(char **argv)
{
	int		i;
	long	x;

	i = 0;
	while (argv[i])
	{
		x = ft_long_atoi(argv[i]);
		if (x > 2147483647 || x < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	error_handling(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		if (!ft_is_number(argv[i]))
			return (1);
		i++;
	}
	if (contain_duplicates(argc, argv) || contain_max_min_int(argv))
		return (1);
	return (0);
}
