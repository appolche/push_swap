#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <unistd.h>
//# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> // DELETE
//# include <fcntl.h>

typedef struct s_stack
{
    struct s_stack *next;
    struct s_stack *prev;
    int     value;
    int     order;
}               t_stack;


typedef struct		s_list
{
	t_stack         *stack_a;
	t_stack         *stack_b;

	char			**argv;
}					t_list;


t_stack *create_stack(int value);
void ft_push_back(t_stack *stack, int value);
void ft_pop_back(t_stack *stack);
t_stack *ft_push_front(t_stack *stack, int value);
t_stack *ft_pop_front(t_stack *stack);
void print_test(t_stack *stack);
void free_stack(t_list **frame);
int	ft_is_number(char *str);
int error_handling(int argc, char **argv);
t_list *frame_init(t_list *frame, int argc, char **argv);
void ft_quick_sort(int *str, int first, int last);
int contain_duplicates(int argc, char **argv);
int contain_maxmin_int(char **argv);
long	ft_long_atoi(const char *str);

#endif