#include "push_swap.h"

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
    stack->next = node;
    node->prev = stack;
    node->next = NULL;
    node->order = -1;
    node->value = value;
}

void ft_pop_back(t_stack **stack)
{
    t_stack *tmp_stack;

    tmp_stack = stack_top(*stack);
    if (tmp_stack->prev)
        tmp_stack->prev->next = NULL;
    else
        *stack = NULL;
    free(tmp_stack);
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

t_stack *stack_top(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return (tmp);
}

int find_stack_size(t_stack *stack)
{
    t_stack *tmp;
    int size;

    tmp = stack;
    size = 0;
    while (tmp->next)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

void print_test(t_stack *stack)
{
    t_stack *tmp;

    if (stack)
    {
        tmp = stack;
        while (tmp->next) {
            tmp = tmp->next;
        }
        while (tmp->prev) {
            printf("Value: %d, ", tmp->value);
            printf("Order: %d\n", tmp->order);
            tmp = tmp->prev;
        }
        printf("Value: %d, ", tmp->value);
        printf("Order: %d\n", tmp->order);
    }
    else
        return ;
}

void free_frame(t_frame **frame)
{
    t_stack *tmp;
    t_stack *st_a;
    t_stack *st_b;

    if ((*frame)->stack_a)
    {
        st_a = (*frame)->stack_a;
        while (st_a)
        {
            tmp = (st_a)->next;
            free(st_a);
            st_a = tmp;
        }
    }
    if ((*frame)->stack_b)
    {
        st_b = (*frame)->stack_b;
        while (st_b)
        {
            tmp = (st_b)->next;
            free(st_b);
            st_b = tmp;
        }
    }
    free(*frame);
}
