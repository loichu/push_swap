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

int	main(int argc, char **argv)
{
    t_stacks	*stacks;

    stacks = init_stacks(&(argv[1]), argc - 1);
	if (stacks->size_a < 5)
        basic_sort(&stacks);
	else
	{
		presort(&stacks);
		printf("got chunks\n");
		sort(&stacks);
	}
	return (0);
}
