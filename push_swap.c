# include "push_swap.h"
# include <stdio.h>

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

int *mass_sort(int argc, char **argv, int *str)
{
    int i;
    int min;
    int max;

    i = 0;
    min = ft_atoi(argv[1]);
    max = ft_atoi(argv[1]);
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
    return (str);
}

int *mass_create(int argc, char **argv) {
    char **tmp;
    int *str;
    int i;
    int j;

    str = (int *) malloc(sizeof(int) * (argc - 1));
    if (!str)
        return (NULL);
    i = 1;
    j = 0;
    tmp = argv;
    while (j < (argc - 1))
    {
        str[j] = ft_atoi(tmp[i]);
        i++;
        j++;
    }
    return (str);
}

t_list *frame_init(t_list *frame, int argc, char **argv)
{
    frame->stack_a = create_stack(ft_atoi(argv[argc-1]));
    if(!frame->stack_a)
        return (NULL);
    frame->stack_b = NULL;
    frame->argv = argv;
    return(frame);
}

int main(int argc, char **argv)
{
    t_list *frame;
    int     *str;
    int     i;

    if (error_handling(argc, argv))
        return(0);
    frame = (t_list*)malloc(sizeof(t_list));
    if (!frame)
        return(0);
    frame_init(frame, argc, argv);
    str = mass_create(argc, argv);
    i = argc - 3;
    while (i >= 0)
    {
        ft_push_back(frame->stack_a, str[i]);
        i--;
    }
    print_test(frame->stack_a);
    free_stack(&frame);
    return(0);
}
