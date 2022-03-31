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

bool	is_swappable(t_node *stk, int last, int dir)
{
	if (!stk || !stk->next || stk->val == last)
		return (false);
	if (dir == 1)
		return (stk->val > stk->next->val);
	else
		return (stk->val < stk->next->val);
}

bool	check_swap(t_stacks **stacks, int last)
{
	bool	sa;
	bool	sb;

	sa = is_swappable((*stacks)->a, last, 1);
	sb = is_swappable((*stacks)->b, last, -1);
	if (sa && sb)
		ss(stacks);
	else if (sa)
		s('a', &((*stacks)->a));
	else if (sb)
		s('b', &((*stacks)->b));
	return (sa);
}

void	check_push(int med, t_stacks **stacks)
{
	if (med > 1 && ((*stacks)->a->val == 0 || (*stacks)->a->val == 1))
		p('b', stacks);
}

void	last_push_swap(t_stacks **stacks, int last)
{
	if ((*stacks)->size_b == 1 && (*stacks)->b->val != 0)
		p('b', stacks);
	if (is_swappable((*stacks)->b, last, -1))
		s('b', &((*stacks)->b));
	while ((*stacks)->size_b > 0)
		p('a', stacks);
}

void	basic_sort(t_stacks **stacks)
{
	bool	rev;
	int 	med;
	int 	last;

	last = (*stacks)->size_a - 1;
	med = (*stacks)->size_a / 2;
	rev = (*stacks)->a->val < med;
	while (!is_ordered((*stacks)->a))
	{
		check_push(med, stacks);
		if (!check_swap(stacks, last))
		{
			if (rev)
				r("ra", stacks);
			else
				r("a", stacks);
		}
		check_push(med, stacks);
	}
	last_push_swap(stacks, last);
}
