// vim: ts=4:sw=4
#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node    *tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	s(char stack, t_node **stk)
{
	swap(stk);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	ss(t_stacks **stacks)
{
	swap(&((*stacks)->a));
	swap(&((*stacks)->b));
	ft_putstr_fd("ss\n", 1);
}