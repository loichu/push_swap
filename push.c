#include "push_swap.h"

void push(char stack, t_stack **to, t_stack **from)
{
	t_stack *tmp;

	if (!*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}