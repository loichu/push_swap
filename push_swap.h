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
void 	r(char stack, t_stack **stk);
void 	revr(char stack, t_stack **stk);
void	rr(t_stack **a, t_stack **b);
void	s(char stack, t_stack **stk);
void	ss(t_stack **a, t_stack **b);
bool	check_order(int dir, t_stack *stk);
void	sort(t_stack **a, t_stack **b);
t_list	*lstget(t_list *lst, int index);
void	pstacks(t_stack *a, t_stack *b);
#endif
