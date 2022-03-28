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

void	get_scores(t_stacks *stacks)
{
	int 	i;
	t_node 	*node;
	t_node 	*stack_a;
	t_node	*prev;

	node = stacks->b;
	i = -1;
	while (++i < stacks->size_b)
	{
		stack_a = stacks->a;
		prev = node_last(stacks->a);
		node->move_a = 0;
		while (!(node->val < stack_a->val && node->val > prev->val))
		{
			//printf("val: %i, prev: %i, curr: %i\n", node->val, prev->val, stack_a->val);
			node->move_a++;
			prev = stack_a;
			stack_a = stack_a->next;
		}
		//printf("got move a\n");
		node->move_b = move_to_top(i, stacks->size_b);
		node->score = calc_score(node);
		node = node->next;
		//printf("next node %i/%i\n", i, stacks->size_b);
	}
}

void	sort(t_stacks **stacks)
{
	while ((*stacks)->size_b > 0)
	{
		//printf("loop\n");
		get_scores(*stacks);
		//printf("got scores\n");
		make_moves(stacks, get_best_node((*stacks)->b));
		p('a', stacks);
	}
	while ((*stacks)->a->val != 0)
		r("a", stacks);

}