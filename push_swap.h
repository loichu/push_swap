#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
    int             val;
    struct s_stack  *next;
}   t_stack;

void 	stk_add_front(t_stack **alst, t_stack *new);
void	stk_add_back(t_stack **alst, t_stack *new);
t_stack	*stk_new(int content);
#endif
