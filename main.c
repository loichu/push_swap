// vim: ts=4:sw=4
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
	ft_putstr_fd("Stack A\t\tStack B\n", 1);
	ft_putstr_fd("-------\t\t-------\n", 1);
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

bool	check_order(int dir, t_stack *stk)
{
	while (stk->next)
	{
		if (dir > 0)
		{
			if (stk->val > stk->next->val)
				return false;
		}
		else
		{
			if (stk->val < stk->next->val)
				return false;
		}
		stk = stk->next;
	}
	return true;
}

void	bubble_sort_single(t_stack **a, int a_last, int med)
{
	bool	a_sorted;
	bool	sa;
	bool	rev;

	a_sorted = check_order(1, *a);
	rev = (*a)->val < med;
	while (!a_sorted)
	{
		if (check_order(1, *a))
			return;
		sa = ((*a)->val != a_last && ((*a)->val > (*a)->next->val));
		if (sa) {
			s('a', a);
		}
		else
		{
			if (rev)
				revr('a', a);
			else
				r('a', a);
		}
	}
}



void	divide(t_stack **a, t_stack **b, int med)
{
	t_stack *start;

	start = NULL;
	while (1)
	{
		if (*a == start)
			break ;
		if ((*a)->val < med)
			push('b', b, a);
		else
		{
			if (!start)
				start = *a;
			r('a', a);
		}
	}
}

void	unify(t_stack **a, t_stack **b)
{
	while ((*b)->next->next)
		push('a', a, b);
}

t_list	*lstget(t_list *lst, int index)
{
	while(index--)
		lst = lst->next;
	return lst;
}

int	main(int argc, char **argv)
{
	int		i;
	int		med;
	int 	size;
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
	size = ft_lstsize(in);
	med = ((t_node *) lstget(in, (argc - 1) / 2)->content)->val;
	incr_order(in);
	if (size < 5)
		bubble_sort_single(&stack_a, ((t_node *) ft_lstlast(in)->content)->val, med);
	else
	{
		divide(&stack_a, &stack_b, med);
		unify(&stack_a, &stack_b);
		pstacks(stack_a, stack_b);
		sort(&stack_a, &stack_b);
	}
	return (0);
}
