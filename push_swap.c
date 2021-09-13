# include "push_swap.h"

void error_handling()
{}


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

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    //int max;
    //int min;
    int current;
    int i;

    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        if(!ft_is_number(argv[i]))
            return(0);
        i++;
    }
    i = argc - 2;
    stack_a = create_node(ft_atoi(argv[argc-1]));
    //min = max = stack_a->value;
    while (i)
    {
        current = ft_atoi(argv[i]);
        /*if (min > current)
            min = current;
        if (max < current)
            max = current;*/
        ft_push_back(stack_a, current);
        i--;
    }
    print_test(stack_a);
    printf("\n\n");

    free_stack(&stack_a);
    free_stack(&stack_b);
}
