# include "push_swap.h"

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

void free_stack(t_list **stack)
{
    t_list *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    free(*stack);
}