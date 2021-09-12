#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <unistd.h>
//# include <stdlib.h>
# include "libft/libft.h"
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

#endif