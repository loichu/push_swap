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
	int 	med;
	int 	last;

	med = (*stacks)->size_a / 2;
	last = (*stacks)->size_a - 1;
	rev = (*stacks)->a->val < med;
	while (!is_ordered((*stacks)->a))
	{
		if ((*stacks)->a->val == 0)
			p('b', stacks);
		sa = ((*stacks)->a->val != last && ((*stacks)->a->val > (*stacks)->a->next->val));
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
	if ((*stacks)->size_b > 0)
		p('a', stacks);
}
