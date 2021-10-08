#include "push_swap.h"

void ft_quick_sort(int *str, int first, int last)
{
    int i;
    int j;
    int pivot;
    int tmp;

    pivot = first;
    i = first;
    j = last;

    if (first < last)
    {
        while(i < j)
        {
            while(str[i] <= str[pivot] && i < last)
                i++;
            while(str[j] > str[pivot])
                j--;
            if(i < j)
            {
                //меняем i и j местами
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
        //меняем pivot и j местами
        tmp = str[pivot];
        str[pivot] = str[j];
        str[j] = tmp;
        ft_quick_sort(str, first, j - 1);
        ft_quick_sort(str, j + 1, last);
    }
}

int str_already_sorted(const int *str, int size)
{
    int	i;

    i = 0;
    while (i < size - 1)
    {
        if (str[i] > str[i + 1])
            return (-1);
        i++;
    }
    return (1);
}

int *str_create_and_sort(int argc, char **argv)
{
    int *str;
    int i;
    int j;

    str = (int *) malloc(sizeof(int) * (argc - 1));
    if (!str)
        return (0);
    i = 1;
    j = 0;
    while (j < (argc - 1))
        str[j++] = ft_atoi(argv[i++]);
    if (str_already_sorted(str, j) == 1)
        return (0);
    else
        ft_quick_sort(str, 0, j - 1);
    return (str);
}