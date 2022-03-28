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
		//printf("got move a\n");
		node->move_b = move_to_top(i, stacks->size_b);
		node->score = calc_score(node);
		node = node->next;
		//printf("next node %i/%i\n", i, stacks->size_b);
	}
}

void    print_stacks(t_node *stack_b, t_node *stack_a)
{
	printf("B\tMB\tS\tMA\tA\n");
	printf("====================================\n");
	while (stack_a && stack_b)
	{
		printf("%i\t%i\t%i\t%i\t%i\n", stack_b->val, stack_b->move_b, stack_b->score, stack_b->move_a, stack_a->val);
		stack_b = stack_b->next;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("%i\t%i\t%i\t%i\n", stack_b->val, stack_b->move_b, stack_b->score, stack_b->move_a);
		stack_b = stack_b->next;
	}
	while (stack_a)
	{
		printf("\t\t\t\t%i\n", stack_a->val);
		stack_a = stack_a->next;
	}
}

void	sort(t_stacks **stacks)
{
	char    *press_enter;

	press_enter = "";
	while ((*stacks)->size_b > 0)
	{
		//printf("loop\n");
		get_scores(*stacks);
		print_stacks((t_node *)(*stacks)->b, (t_node *)(*stacks)->a);
		read(1, press_enter, 1);
		//printf("got scores\n");
		make_moves(stacks, get_best_node((*stacks)->b));
		p('a', stacks);
	}
	while ((*stacks)->a->val != 0)
		r("a", stacks);

}