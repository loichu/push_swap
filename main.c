#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef	struct s_node
{
	int	val;
	int	ini;
	int	ord;
}	t_node;

void	del_node(t_node *node)
{
	free(node);
}

t_node	*create_node(int val, int ini)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	ret->val = val;
	ret->ini = ini;
	ret->ord = -1;
	return (ret);
}

void	raise_error(int errcode)
{
	ft_putstr_fd("Error\n", 1);
	exit(errcode);
}

void	incr_order(t_list *node)
{
	if (!node)
		return ;
	t_node	*c;
	t_node	*n;
	n = (t_node *)node->next->content;
	c = (t_node *)node->content;
	n->ord = c->ord + 1;
	incr_order(node->next);
}

void	ins_node(t_list **lst, t_list *new, t_list *prev, t_list *curr)
{
		
	if (!prev)
		*lst = new;
	else
		prev->next = new;
	new->next = curr;
	//incr_order(curr);
}

void	lstadd_sort(t_list **lst, t_node *node)
{
	t_node	*curr_node;
	t_list	*curr;
	t_list	*prev;
	t_list	*new;
	int		i;

	curr = *lst;
	new = ft_lstnew(node);
	prev = NULL;
	i = 0;
	while (curr)
	{
		curr_node = (t_node *)curr->content;
		curr_node->ord = i++;
		if (node->val == curr_node->val)
			raise_error(1);
		else if (node->val < curr_node->val)
			return ins_node(lst, new, prev, curr);
		prev = curr;
		curr = curr->next;
	}
	prev->next = new;
}

void	pval(void *node)
{
	t_node	*n;
	n = (t_node *)node;
	ft_putnbr_fd(n->val, 1);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(n->ini, 1);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(n->ord, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*in;

	i = 1;
	in = ft_lstnew(create_node(ft_atoi(argv[i]), i - 1));
	while(++i < argc)
		lstadd_sort(&in, create_node(ft_atoi(argv[i]), i - 1));
	ft_putstr_fd("Value\tInit\tOrder\n", 1);
	ft_lstiter(in, *pval);
	return (0);
}
