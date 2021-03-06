/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:25:46 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:26:30 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*r;

	r = (t_node *)malloc(sizeof(t_node));
	if (!r)
		return (NULL);
	r->val = val;
	r->next = NULL;
	r->move_a = 0;
	r->move_b = 0;
	r->score = 0;
	return (r);
}

void	node_addback(t_node **list, t_node *new)
{
	t_node	*iter;

	if (!list)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	iter = *list;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

void	node_addfront(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

void	ins_node(t_list **lst, t_list *new, t_list *prev, t_list *curr)
{
	if (!prev)
		*lst = new;
	else
		prev->next = new;
	new->next = curr;
}

t_node	*get_best_node(t_node *stack)
{
	t_node	*best_node;

	best_node = NULL;
	while (stack)
	{
		if (stack->score >= 0
			&& (!best_node || stack->score < best_node->score))
			best_node = stack;
		stack = stack->next;
	}
	return (best_node);
}
