//
// Created by loichu on 07.03.22.
//

#include "push_swap.h"

void	lstadd_sort(t_list **lst, t_node *node)
{
	t_node 	*curr_node;
	t_list	*curr;
	t_list	*prev;
	t_list	*new;

	curr = *lst;
	new = ft_lstnew(node);
	if (!curr)
		*lst = new;
	prev = NULL;
	while (curr)
	{
		curr_node = (t_node *)curr->content;
		if (node->val == curr_node->val)
			return raise_error(1);
		else if (node->val < curr_node->val)
			return ins_node(lst, new, prev, curr);
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = new;
}

void	replace_values(t_list *sorted)
{
	static int	index = 0;
	t_node 		*node;

	node = (t_node *)sorted->content;
	if (index == 0)
		node->score = -1;
	node->val = index++;
	if (sorted->next)
		replace_values(sorted->next);
	else
		node->score = -1;
	free(sorted);
}

int	r_get_number(char *s, int i, int sign)
{
	static int	limit = INT_MAX / 10;
	int 		u;

	if (!*s)
		return (i * sign);
	u = *s - 48;
	if (!ft_isdigit(*s) || i > limit || (i == limit
		&& ((sign > 0 && u > 7) || (sign < 0 && u > 8))))
		raise_error(1);
	return (r_get_number(++s, i * 10 + u, sign));
}

int	my_atoi(char *s)
{
	int	sign;

	if (*s == '-')
	{
		s++;
		sign = -1;
	}
	else
		sign = 1;
	return (r_get_number(s, 0, sign));
}

t_node *analyze(char **input, int size)
{
	int		i;
	t_node	*initial;
	t_list	*sorted;
	t_node	*node;

	i = -1;
	initial = NULL;
	sorted = NULL;
	while (++i < size)
	{
		node = new_node(my_atoi(input[i]));
		node_addback(&initial, node);
		lstadd_sort(&sorted, node);
	}
	replace_values(sorted);
	return (initial);
}