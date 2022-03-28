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

//void	basic_sort(t_stacks **stacks)
//{
//	int		med;
//
//	med = ((*stacks)->size_a + 1) / 2;
//	printf("med: %i\n", med);
//	while (true)
//	{
//		if (is_ordered((*stacks)->a))
//			return ;
//		if ((*stacks)->a->val > med)
//			r("a", stacks);
//		else if ((*stacks)->a->val > (*stacks)->a->next->val)
//			s('a', &((*stacks)->a));
//	}
//}

//void	check_push_zero(t_stacks **stacks)
//{
//	if ((*stacks)->a->val == 0)
//		p('b', stacks);
//}

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
