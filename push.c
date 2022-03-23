#include "push_swap.h"

void	push(t_node **to, t_node **from)
{
	t_node *tmp;

	if (!*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

void	p(char stack, t_stacks **stacks)
{
	if (stack == 'a')
	{
		push(&(*stacks)->a, &(*stacks)->b);
		(*stacks)->size_a++;
		(*stacks)->size_b--;
	}
	else if (stack == 'b')
	{
		push(&(*stacks)->b, &(*stacks)->a);
		(*stacks)->size_a--;
		(*stacks)->size_b++;
	}
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	p_chunk(t_stacks **stacks, t_list **chunks)
{
	t_chunk	*first_chunk;
	t_chunk	*last_chunk;
	t_node	*node;

	first_chunk = (t_chunk *)(*chunks)->next->content;
	last_chunk = (t_chunk *)(*chunks)->content;
	node = (t_node *)(*stacks)->a;
	(*stacks)->a = node->next;
	(*stacks)->size_a--;
	ft_putstr_fd("pb\n", 1);
	if (is_in_chunk(node, first_chunk))
	{
		first_chunk->size++;
		node_addfront(&(first_chunk->nodes), node);
	}
	else if (is_in_chunk(node, last_chunk))
	{
		last_chunk->size++;
		node_addback(&(last_chunk->nodes), node);
		chunks_r("b", stacks);
	}
	(*stacks)->size_b++;
}