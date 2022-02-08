#include "push_swap.h"

void	sort(t_stack **a, t_stack **b, int a_frst, int b_frst)
{
	bool	a_sorted;
	bool	b_sorted;
	bool	sa;
	bool	sb;

	a_sorted = check_order(1, *a);
	b_sorted = check_order(-1, *b);
	while (!(a_sorted && b_sorted))
	{
		sa = ((*a)->next && (*a)->next->val != a_frst) && ((*a)->val > (*a)->next->val);
		sb = ((*b)->next && (*b)->next->val != b_frst) && ((*b)->val < (*b)->next->val);
		if (sa && sb)
			ss(a, b);
		else if (sa)
			s('a', a);
		else if (sb)
			s('b', b);
		a_sorted = check_order(1, *a);
		b_sorted = check_order(-1, *b);
		if (!(a_sorted || b_sorted))
			rr(a, b);
		else if (!a_sorted)
			r('a', a);
		else if (!b_sorted)
			r('b', b);
		else
			return ;
	}
}