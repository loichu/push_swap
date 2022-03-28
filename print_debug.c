#include "push_swap.h"

bool    print_chunk_node(t_chunk *chunk)
{
	static t_node   *node;
	static t_chunk  *prev_chunk;

	if (!chunk)
		return (false);
	if (!node)
		node = chunk->nodes;
	if (node)
		printf("%i\t", node->val);
	else
		printf("\t");
	if (chunk != prev_chunk)
	{
		printf("Chunk: %i → %i\t", chunk->min, chunk->max);
		prev_chunk = chunk;
	}
	if (!node || !node->next)
	{
		printf("count: %i", chunk->size);
		node = NULL;
		return (false);
	}
	node = node->next;
	return (true);
}

void    print_stack_chunks(t_list *chunks, t_node *stack_a)
{
	t_chunk *chunk;

	chunk = (t_chunk *)chunks->content;
	printf("A\tMA\tS\tMB\tB\n");
	printf("====================================\n");
	printf("\t\t\t\t");
	while (print_chunk_node(chunk))
	{
		printf("\n");
		printf("\t\t\t\t");
	}
	printf("\n");
	chunks = chunks->next;
	chunk = (t_chunk *)chunks->content;
	printf("%i\t%i\t%i\t%i\n", stack_a->val, stack_a->move_a, stack_a->score, stack_a->move_b);
	stack_a = stack_a->next;
	while (stack_a)
	{
		printf("%i\t%i\t%i\t%i\t", stack_a->val, stack_a->move_a, stack_a->score, stack_a->move_b);
		if (!print_chunk_node(chunk))
		{
			if (chunks->next)
			{
				chunks = chunks->next;
				chunk = (t_chunk *)chunks->content;
			}
			else
				chunk = NULL;
		}
		stack_a = stack_a->next;
		printf("\n");
	}
	while (chunks)
	{
		printf("\t\t\t\t");
		if (!print_chunk_node(chunk))
		{
			if (chunks->next)
			{
				chunks = chunks->next;
				chunk = (t_chunk *)chunks->content;
			}
			else
				chunks = NULL;
		}
		printf("\n");
	}
}