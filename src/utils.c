//
// Created by Loic Humbert on 3/31/22.
//

#include "push_swap.h"

bool	is_ordered(t_node *stk)
{
	while (stk->next)
	{
		if (stk->val > stk->next->val)
			return (false);
		stk = stk->next;
	}
	return (true);
}