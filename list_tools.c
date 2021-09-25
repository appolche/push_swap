# include "push_swap.h"

t_stack *create_stack(int value)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return(NULL);
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    node->order = 0;
    return (node);
}

void ft_push_back(t_stack *stack, int value)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    while (stack->next)
    {
        stack = stack->next;
    }
    node->prev = stack;
    node->next = NULL;
    node->value = value;
    stack->next = node;
}

void ft_pop_back(t_stack *stack)
{
    while (stack->next)
    {
        stack = stack->next;
    }
    stack->prev->next = NULL;
    free(stack);
}

t_stack *ft_push_front(t_stack *stack, int value)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));

    if (stack && stack->prev == NULL)
    {
        node->prev = NULL;
        node->next = stack;
        node->value = value;
        stack->prev = node;
    }
    else 
        node = create_stack(value);
    return (node);
}

t_stack *ft_pop_front(t_stack *stack)
{
    t_stack *tmp;

    tmp = NULL;
    if (stack && stack->next)
    {
        tmp = stack->next;
        stack->next->prev = NULL;
    }
    free(stack);
    return (tmp);
}

void print_test(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

void free_stack(t_list **frame)
{
    t_stack *tmp;
    t_stack *st_a = (*frame)->stack_a;
    t_stack *st_b = (*frame)->stack_b;

    while (st_a)
    {
        tmp = (st_a)->next;
        free(st_a);
        st_a = tmp;
    }
    while (st_b)
    {
        tmp = (st_b)->next;
        free(st_b);
        st_b = tmp;
    }
    free(*frame);
}