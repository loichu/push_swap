/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:29:09 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:31:28 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stacks	*free_stacks(t_stacks *stacks)
{
	t_node	*freed;

	while (stacks->a)
	{
		freed = stacks->a;
		stacks->a = stacks->a->next;
		free(freed);
	}
	while (stacks->b)
	{
		freed = stacks->b;
		stacks->b = stacks->b->next;
		free(freed);
	}
	free(stacks);
	return (NULL);
}

void	make_b(t_list *chunks, t_stacks **stacks)
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

t_stacks	*parse_args(int argc, char **argv)
{
	int			nb_args;
	char		**args;
	t_stacks	*stacks;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &(argv[1]);
	nb_args = 0;
	while (args[nb_args])
		nb_args++;
	if (nb_args < 2)
		exit(0);
	stacks = init_stacks(args, nb_args);
	if (argc == 2)
	{
		while (nb_args)
			free(args[--nb_args]);
		free(args);
	}
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*chunks;
	int			nb_chunks;

	stacks = parse_args(argc, argv);
	if (stacks->size_a < 6)
	{
		basic_sort(&stacks);
		stacks = free_stacks(stacks);
		return (0);
	}
	else if (stacks->size_a > 250)
		nb_chunks = 5;
	else
		nb_chunks = 2;
	chunks = presort(&stacks, nb_chunks);
	make_b(chunks, &stacks);
	sort(&stacks);
	stacks = free_stacks(stacks);
	return (0);
}
