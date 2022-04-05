/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:22:49 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:22:56 by lhumbert         ###   ########.fr       */
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

void	raise_error(int errcode)
{
	ft_putstr_fd("Error\n", 1);
	exit(errcode);
}
