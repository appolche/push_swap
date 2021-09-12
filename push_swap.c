# include "push_swap.h"





int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list *tmp;
    int max = ft_atoi(argv[1]);
    int min = ft_atoi(argv[1]);
    int current;

    int i = 2;
    stack_a = create_node(ft_atoi(argv[1]));
    min = max = stack_a->value;
    while (argv[i])
    {
        current = ft_atoi(argv[i]);
        if (min > current)
            min = current;
        if (max < current)
            max = current;
        ft_push_back(stack_a, current);
        i++;
    }
    do_sa(&stack_a);
    //do_rb(&stack_b);
    //do_rr(&stack_a, &stack_b);
    printf("\n\n");
    print_test(stack_a);
    printf("\n\n");
    //print_test(stack_b);
    while (stack_a)
    {
        tmp = stack_a->next;
        free(stack_a);
        stack_a = tmp;
    }
    free(stack_a);
}
