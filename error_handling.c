#include "push_swap.h"

int	write_error(int i)
{
    write(1, "Error\n", 6);
    return (i);
}

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

int	ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
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

int contain_duplicates(int argc, char **argv)
{
    int j;
    int k;
    int i;

    j = 1;
    while (j < argc)
    {
        i = 1;
        k = 0;
        while(argv[i])
        {
            if (!ft_strcmp(argv[i], argv[j])) //if 0 - не входим
                k++;
            i++;
        }
        if (k >= 2)
            return(1);
        j++;
    }
    return(0);
}

int contain_maxmin_int(char **argv)
{
    int i;
    long x;

    i = 0;
    while (argv[i])
    {
        x = ft_long_atoi(argv[i]);
        if (x > 2147483647 || x < -2147483648)
            return(1);
        i++;
    }
    return(0);
}

int error_handling(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc < 2)
        return (1);
    while (argv[i])
    {
        if(!ft_is_number(argv[i]))
        {
            ft_putstr_fd("Error_notdigit\n", 1);
            return (1);
        }
        i++;
    }
    if (contain_duplicates(argc, argv))
    {
        ft_putstr_fd("Error_duplicates\n", 1);
        return (1);
    }
    if (contain_maxmin_int(argv))
    {
        ft_putstr_fd("Error_maxmin\n", 1);
        return (1);
    }
    return (0);
}

