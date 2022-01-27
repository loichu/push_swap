// vim: ts=4:sw=4
#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	s(char stack, t_stack **stk)
{
	swap(stk);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss", 1);
	ft_putchar_fd('\n', 1);
}