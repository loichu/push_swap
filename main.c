#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef	struct s_node
{
	int	val;
	int	ini;
	int	ord;
}	t_node;

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

void	pval(void *node)
{
	t_node	*n;
	n = (t_node *)node;
	ft_putnbr_fd(n->val, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*in;

	i = 1;
	in = ft_lstnew(create_node(ft_atoi(argv[i]), i - 1));
	while(++i < argc)
		ft_lstadd_back(&in, ft_lstnew(create_node(ft_atoi(argv[i]), i - 1)));
	ft_lstiter(in, *pval);
	return (0);
}
