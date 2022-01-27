#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
void 	push(char stack, t_stack **to, t_stack **from);
void 	rotate(char stack, t_stack **stk);
void 	reverse(char stack, t_stack **stk);
/*void 	ra(t_stack **a);
void 	rb(t_stack **b);*/
#endif
