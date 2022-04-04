/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:26:41 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:28:41 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top(int index, int stack_size)
{
	if (index > stack_size / 2)
		index = (stack_size - index) * -1;
	return (index);
}

int	calc_score(t_node *node)
{
	if (node->move_a * node->move_b > 0)
		return (max(abs(node->move_a), abs(node->move_b)));
	return (abs(node->move_a) + abs(node->move_b));
}

void	exec_rotates(t_stacks **stacks, char stack, int moves, bool chunk)
{
	char	*cmd;
	int		i;

	i = 0;
	cmd = (char *)malloc(3 * sizeof(char));
	if (moves < 0)
		cmd[i++] = 'r';
	cmd[i++] = stack;
	cmd[i] = '\0';
	moves = abs(moves);
	while (moves--)
	{
		if (chunk)
			chunks_r(cmd, stacks);
		else
			r(cmd, stacks);
	}
	free(cmd);
}

void	exec_rotates_together(t_stacks **stacks, t_node *best_node, bool chunk)
{
	char	*cmd;
	int		moves;

	moves = min(abs(best_node->move_a), abs(best_node->move_b));
	if (best_node->move_a > 0)
	{
		cmd = "r";
		best_node->move_a -= moves;
		best_node->move_b -= moves;
	}
	else
	{
		cmd = "rr";
		best_node->move_a += moves;
		best_node->move_b += moves;
	}
	while (moves--)
	{
		if (chunk)
			chunks_r(cmd, stacks);
		else
			r(cmd, stacks);
	}
}

t_node	*node_last(t_node *stk)
{
	while (stk->next)
		stk = stk->next;
	return (stk);
}
