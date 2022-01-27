#include "push_swap.h"

void rotate(char stack, t_stack **stk)
{
	t_stack *tmp;

	if (!*stk)
		return ;
	tmp = *stk;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stk;
	*stk = (*stk)->next;
	tmp->next->next = NULL;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void reverse(char stack, t_stack **stk)
{
	t_stack *tmp;
	t_stack *prev;

	if (!(*stk && (*stk)->next))
		return ;
	prev = *stk;
	tmp = (*stk)->next;
	while (tmp->next)
	{
		prev = prev->next;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stk;
	*stk = tmp;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}