#include "libft/libft.h"

typedef struct s_list
{
    struct s_list *next;
    int value;
}               t_list;

t_list *create_node(int value)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));

    node->next = NULL;
    node->value = value;
    return (node);
}

void ft_push_back(t_list *head, int value)
{
    while (head->next)
    {
        head = head->next;
    }
    head->next = create_node(value);
}

void ft_pop_back(t_list *head)
{
    t_list *tmp;

    while (head->next)
    {
        tmp = head;
        head = head->next;
    }
    free (head);
    tmp->next = NULL;
}

int main(int argc, char **argv)
{
    t_list *head;
    int i = 2;
    head = create_node(ft_atoi(argv[1]));
    while (argv[i])
    {
        ft_push_back(head, ft_atoi(argv[i]));
        i++;
    }
    t_list *tmp = head;
    while (tmp->next)
    {
        ft_putnbr_fd(tmp->value, 1);
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    ft_putnbr_fd(tmp->value, 1);
    write(1, "\n\n", 2);
    ft_pop_back(head);
    tmp = head;
    while (tmp->next)
    {
        ft_putnbr_fd(tmp->value, 1);
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    ft_putnbr_fd(tmp->value, 1);
    write(1, "\n\n", 2);
    while (head->next) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(head);
}


