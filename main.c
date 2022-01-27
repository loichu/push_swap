#include "push_swap.h"

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
	ret->ord = 0;
	return (ret);
}

void	raise_error(int errcode)
{
	ft_putstr_fd("Error\n", 1);
	exit(errcode);
}

void	incr_order(t_list *node)
{
	if (!node->next)
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
}

void	lstadd_sort(t_list **lst, t_node *node)
{
	t_node	*curr_node;
	t_list	*curr;
	t_list	*prev;
	t_list	*new;

	curr = *lst;
	new = ft_lstnew(node);
	prev = NULL;
	while (curr)
	{
		curr_node = (t_node *)curr->content;
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
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(n->ini, 1);
	ft_putchar_fd('\t', 1);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(n->ord, 1);
	ft_putchar_fd('\n', 1);
}

void	pstacks(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Stack A\t\t\tStack B\n", 1);	
	ft_putstr_fd("-------\t\t\t-------\n", 1);	
	while (a || b)
	{
		if (a)
		{
			ft_putnbr_fd(a->val, 1);
			a = a->next;
		}
		ft_putstr_fd("\t\t", 1);
		if (b)
		{
			ft_putnbr_fd(b->val, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}

void	sort(t_stack *a, t_stack *b, int med)
{
	bool	sorted;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
	}
}

void	divide(t_stack **a, t_stack **b, int med)
{
	t_stack i;

	i = *a;
	while (i)
	{
		if (i->val > )	
		i = i->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		med;
	t_list	*in;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	in = ft_lstnew(create_node(ft_atoi(argv[i]), i - 1));
	stack_a = stk_new(ft_atoi(argv[i]));
	stack_b = NULL;
	while (++i < argc)
	{
		lstadd_sort(&in, create_node(ft_atoi(argv[i]), i - 1));
		stk_add_back(&stack_a, stk_new(ft_atoi(argv[i])));
	}
	med = i / 2;
	ft_putstr_fd("Value\t\tInit\t\tOrder\n", 1);
	incr_order(in);
	ft_lstiter(in, *pval);
	pstacks(stack_a, stack_b);
	return (0);
}
