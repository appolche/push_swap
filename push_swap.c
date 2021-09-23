# include "push_swap.h"
# include <stdio.h>

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

size_t error_handling(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc < 2)
        return (write(2, "Error\n", 6));
    while (argv[i])
    {
        if(!ft_is_number(argv[i]))
            return(write(2, "Error\n", 6));
        i++;
    }
    return (0);
}

void find_algorithm();

t_list *frame_init(t_list *frame, int argc, char **argv)
{
    frame->stack_a = create_stack(ft_atoi(argv[argc-1]));
    if(!frame->stack_a)
        return (NULL);
    frame->stack_b = NULL;
    frame->argv = argv;
    return(frame);
}

void ft_quick_sort(int *str, int min, int max)
{
    if (min < max)
    {
        int left = min, right = max, middle = str[(left + right) / 2];
        do
        {
            while (str[left] < middle) left++;
            while (str[right] > middle) right--;
            if (left <= right)
            {
                int tmp = str[left];
                str[left] = str[right];
                str[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        ft_quick_sort(str, min, right);
        ft_quick_sort(str, left, max);
    }
}

int main(int argc, char **argv)
{
    t_list *frame;
    char **tmp;
    int *str;
    int current;
    int i;
    int min = ft_atoi(argv[1]);
    int max = ft_atoi(argv[1]);

    error_handling(argc, argv);

    str = (int*)malloc(sizeof(int)*(argc-1));
    if (!str)
        return (0);
    i = 1;
    tmp = argv;
    while (tmp[i])
    {
        str[i-1] = ft_atoi(tmp[i]);
        i++;
    }
    i = 0;
    while (i != (argc-1))
    {
        if (str[i] > max)
            max = str[i];
        if (str[i] < min)
            min = str[i];
        printf("%d \n", str[i]);
        i++;
    }
    printf("\n%d\n\n", max);

    frame = (t_list*)malloc(sizeof(t_list));
    if (!frame)
        return(0);
    frame_init(frame, argc, argv);
    i = argc - 2;
    while (i >= 0)
    {
        ft_push_back(frame->stack_a, str[i]);
        i--;
    }

    printf("%d\n\n", min);

    ft_quick_sort(str, 0, i-1);
    i = 0;
    while (i != (argc-1))
    {
        if (str[i] > max)
            max = str[i];
        if (str[i] < min)
            min = str[i];

        printf("%d \n", str[i]);
        i++;
    }

    print_test(frame->stack_a);
    free_stack(&frame);
    return(0);
}
