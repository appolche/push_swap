/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:14:21 by dleaves           #+#    #+#             */
/*   Updated: 2021/10/10 20:39:43 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				order;
}				t_stack;

typedef struct s_frame
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
}				t_frame;

t_frame	*create_frame(int argc, char **argv, int *str);
t_stack	*create_stack(int value);
t_frame	*frame_init(t_frame *frame, int argc, char **argv);
void	index_stack(t_stack *stack_a, int *str);
int		order_search(int value, const int *sorted_str);

t_stack	*stack_top(t_stack *stack);
void	ft_push_back(t_stack *stack, int value);
void	ft_pop_back(t_stack **stack);
void	free_frame(t_frame **frame);
int		find_stack_size(t_stack *stack);

int		error_handling(int argc, char **argv);
int		write_error(int i);
int		contain_duplicates(int argc, char **argv);
int		contain_max_min_int(char **argv);
int		str_already_sorted(const int *str, int size);
int		*str_create_and_sort(int argc, char **argv);
void	ft_quick_sort(int *str, int first, int last);
void	ft_swap_elements(int *str, int i, int j);

void	radix_sort_big_stack(int argc, t_frame *frame);
void	sort_small_stack(t_frame *frame);
void	sort_4_or_5_elements(t_frame *frame);
void	sort_3_elements(t_frame *frame);
void	sort_2_elements(t_frame *frame);

void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

long	ft_long_atoi(const char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_is_number(char *str);

#endif
