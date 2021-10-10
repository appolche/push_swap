#include "push_swap.h"

long	ft_long_atoi(const char *str)
{
    long		res;
    long		n;

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

int	ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_is_number(char *str)
{
    int	i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
