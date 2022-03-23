/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:53:52 by lhumbert          #+#    #+#             */
/*   Updated: 2022/03/23 20:59:20 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_get(t_node *stk, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		stk = stk->next;
	return (stk);
}

bool	is_ordered(t_node *stk)
{
	while (stk->next)
	{
		if (stk->val > stk->next->val)
			return (false);
		stk = stk->next;
	}
	return (true);
}

void	basic_sort(t_stacks **stacks)
{
	bool	sa;
	bool	rev;
	int		med;

	med = node_get((*stacks)->a, (*stacks)->size_a / 2)->val;
	while (true)
	{
		if (is_ordered((*stacks)->a))
			return ;
		rev = ((*stacks)->a)->val < med;
		sa = (((*stacks)->a)->val != node_last((*stacks)->a)->val
				&& (((*stacks)->a)->val > ((*stacks)->a)->next->val));
		if (sa)
			s('a', &((*stacks)->a));
		else
		{
			if (rev)
				r("ra", stacks);
			else
				r("a", stacks);
		}
	}
}
