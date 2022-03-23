#include "push_swap.h"

void	scores(t_stacks *stacks, t_list *chunks)
{
	int 	i;
	t_node 	*node;

	node = stacks->a;
	i = -1;
	while (++i < stacks->size_a)
	{
		if (node->score == -1)
		{
			node = node->next;
			continue ;
		}
		node->move_a = move_to_top(i, stacks->size_a);
		node->move_b = move_to_chunk(node, chunks, stacks->size_b);
		node->score = calc_score(node);
		if (is_in_chunk(node, (t_chunk *)chunks->content))
			node->score++;
		node = node->next;
	}
}

void	rotate_stacks(t_stacks **stacks, t_node *best_node)
{
	if (best_node->move_a * best_node->move_b > 0)
		exec_rotates_together(stacks, best_node, true);
	if (best_node->move_a)
		exec_rotates(stacks, 'a', best_node->move_a, true);
	if (best_node->move_b)
		exec_rotates(stacks, 'b', best_node->move_b, true);
}

void	moves(t_stacks **stacks, t_list **chunks)
{
	t_node	*best_node;
	t_chunk	*first_chunk;
	t_chunk	*last_chunk;

	best_node = get_best_node((*stacks)->a);
	first_chunk = (t_chunk *)(*chunks)->next->content;
	last_chunk = (t_chunk *)(*chunks)->content;
	while (!is_in_chunk(best_node, first_chunk)
		&& !is_in_chunk(best_node, last_chunk))
	{
		rotate_chunks(chunks);
		first_chunk = (t_chunk *)(*chunks)->next->content;
		last_chunk = (t_chunk *)(*chunks)->content;
	}
	rotate_stacks(stacks, best_node);
}

t_list	*presort(t_stacks **stacks)
{
	t_list	*chunks;
	int 	nb_chunks;
	int 	chunk_size;
	int 	last_chunk_size;

	nb_chunks = 4;
	chunk_size = (*stacks)->size_a / nb_chunks;
	last_chunk_size = (*stacks)->size_a % chunk_size;
	if (last_chunk_size) {
		nb_chunks++;
	}
	chunks = init_chunks(chunk_size, nb_chunks, last_chunk_size);
	while ((*stacks)->size_a > 2)
	{
		scores(*stacks, chunks);
		moves(stacks, &chunks);
		p_chunk(stacks, &chunks);
	}
	return (chunks);
}