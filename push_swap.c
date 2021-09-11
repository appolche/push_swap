#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    int value;
} t_list;

t_list *create_node(int value)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return (node);
}

void ft_push_back(t_list *stack, int value)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    while (stack->next)
    {
        stack = stack->next;
    }
    node->prev = stack;
    node->next = NULL;
    node->value = value;
    stack->next = node;
}

void ft_pop_back(t_list *stack)
{
    while (stack->next)
    {
        stack = stack->next;
    }
    stack->prev->next = NULL;
    free(stack);
}

t_list *ft_push_front(t_list *stack, int value)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));

    if (stack && stack->prev == NULL)
    {
        node->prev = NULL;
        node->next = stack;
        node->value = value;
        stack->prev = node;
    }
    else 
        node = create_node(value);
    return (node);
}

t_list *ft_pop_front(t_list *stack)
{
    t_list *tmp;

    if (stack && stack->next)
    {
        tmp = stack->next;
        stack->next->prev = NULL;
    }
    free(stack);
    return (tmp);
}

void print_test(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

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
