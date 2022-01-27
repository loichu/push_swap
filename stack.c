#include "push_swap.h"

void 	stk_add_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}

void	stk_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*iter;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	iter = *alst;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

t_stack	*stk_new(int val)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->val = val;
	ret->next = NULL;
	return (ret);
}
