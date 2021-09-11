#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		n;

	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	res = 0;
	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (n * res);
}
