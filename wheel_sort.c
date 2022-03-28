#include "push_swap.h"

void	make_moves(t_stacks **stacks, t_node *best_node)
{
	if (best_node->move_a * best_node->move_b > 0)
		exec_rotates_together(stacks, best_node, false);
	if (best_node->move_a)
		exec_rotates(stacks, 'a', best_node->move_a, false);
	if (best_node->move_b)
		exec_rotates(stacks, 'b', best_node->move_b, false);
}

int	get_move_a(int node_val, t_node *stack_a, int a_size)
{
	t_node	*prev;
	int 	move;

	move = 0;
	prev = node_last(stack_a);
	while (!(node_val < stack_a->val && node_val > prev->val))
	{
		move++;
		prev = stack_a;
		stack_a = stack_a->next;
	}
	if (move > a_size / 2)
		move = (a_size - move) * -1;
	return (move);
}

void	get_scores(t_stacks *stacks)
{
	int 	i;
	t_node 	*node;

	node = stacks->b;
	i = -1;
	while (++i < stacks->size_b)
	{
		node->move_a = get_move_a(node->val, stacks->a, stacks->size_a);
		node->move_b = move_to_top(i, stacks->size_b);
		node->score = calc_score(node);
		node = node->next;
	}
}

void	sort(t_stacks **stacks)
{
	char	*cmd;

	while ((*stacks)->size_b > 0)
	{
		get_scores(*stacks);
		make_moves(stacks, get_best_node((*stacks)->b));
		p('a', stacks);
	}
	if ((*stacks)->a->val < (*stacks)->size_a / 2)
		cmd = "ra";
	else
		cmd = "a";
	while ((*stacks)->a->val != 0)
		r(cmd, stacks);
}