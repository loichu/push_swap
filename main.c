// vim: ts=4:sw=4
#include "push_swap.h"

t_stacks	*init_stacks(char **input, int size)
{
    t_stacks	*stacks;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return (NULL);
    stacks->a = analyze(input, size);
    stacks->size_a = size;
    stacks->b = NULL;
    stacks->size_b = 0;
    return (stacks);
}

void	free_chunks(t_list *chunks, t_stacks **stacks)
{
	t_list	*prev;
	t_node	*last_b;

	rotate_chunks(&chunks);
	last_b = ((t_chunk *)chunks->content)->nodes;
	while (chunks)
	{
		if (!(*stacks)->b)
			(*stacks)->b = last_b;
		else
			last_b->next = ((t_chunk *)chunks->content)->nodes;
		prev = chunks;
		chunks = chunks->next;
		free(prev->content);
		free(prev);
		while (last_b->next)
			last_b = last_b->next;
	}
}

int	main(int argc, char **argv)
{
    t_stacks	*stacks;
	t_list		*chunks;

    stacks = init_stacks(&(argv[1]), argc - 1);
	if (stacks->size_a < 5)
        basic_sort(&stacks);
	else
	{
		chunks = presort(&stacks);
		//printf("got chunks\n");
		free_chunks(chunks, &stacks);
		sort(&stacks);
	}
	return (0);
}
