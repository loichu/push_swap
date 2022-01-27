#include "push_swap.h"

void	rotate(t_stack **stk)
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
}

void	reverse(t_stack **stk)
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
}

void	r(char stack, t_stack **stk)
{
	rotate(stk);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	revr(char stack, t_stack **stk)
{
	reverse(stk);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd('\n', 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr", 1);
	ft_putchar_fd('\n', 1);
}