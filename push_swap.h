#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <unistd.h>
//# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> // DELETE
//# include <fcntl.h>

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    int     value;
}               t_list;


typedef struct		s_frame
{
	t_list          *stack_a;
	t_list          *stack_b;

	char			**argv;
}					t_frame;


t_list *create_node(int value);
void ft_push_back(t_list *stack, int value);
void ft_pop_back(t_list *stack);
t_list *ft_push_front(t_list *stack, int value);
t_list *ft_pop_front(t_list *stack);
void print_test(t_list *stack);
void free_stack(t_list **stack);

#endif