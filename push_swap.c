# include "push_swap.h"
# include <stdio.h>

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

int order_search(int value, const int *sorted_str, t_list *frame)
{
    int i;

    i = 0;
    while(sorted_str[i])
    {
        if (sorted_str[i] == value)
        {
            return (i + 1);
        }
        i++;
    }
    return(0);
}

int *mass_sort(int argc, char **argv, int *str)
{
    int i;
    int min;
    int max;
    int *sorted_str;

    i = 0;
    /*min = ft_atoi(argv[1]);
    max = ft_atoi(argv[1]);
    while (i != (argc-1))
    {
        if (str[i] > max)
            max = str[i];
        if (str[i] < min)
            min = str[i];
        printf("%d ", str[i]);
        i++;
    }
    printf("\n\n%d\n", min);
    printf("%d\n\n", max);*/
    sorted_str = (int *) malloc(sizeof(int) * (argc - 1));
    while (i < argc - 1)
    {
        sorted_str[i] = str[i];
        i++;
    }
    ft_quick_sort(sorted_str, 0, i-1);
    return (sorted_str);
}

int *mass_create(int argc, char **argv)
{
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
    t_stack *tmp_list;
    int     *str;
    int     *tmp;
    int     i;
    int order;

    if (error_handling(argc, argv))
        return(0);
    str = mass_create(argc, argv);
    tmp = mass_sort(argc, argv, str);

   // order = order_search(str[i], tmp, frame);



    frame = (t_list*)malloc(sizeof(t_list));
    if (!frame)
        return(0);
    frame_init(frame, argc, argv);
    i = argc - 3;
    while (i >= 0)
    {
        ft_push_back(frame->stack_a, str[i]);
        i--;
    }
    tmp_list = frame->stack_a;
    while(tmp_list)
    {
        tmp_list->order = order_search(tmp_list->value, tmp, frame);
        printf("%d, ", tmp_list->order);
        tmp_list = tmp_list->next;
    }

    //print_test(frame->stack_a);
    free_stack(&frame);
    return(0);
}
