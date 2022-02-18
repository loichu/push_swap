#include "push_swap.h"

int 	stack_size(t_stack *stk)
{
	int count;

	count = 0;
	while (stk)
	{
		count++;
		stk = stk->next;
	}
	return count;
}

int 	stack_get(t_stack *stack, int index)
{
	while(index--)
		stack = stack->next;
	return stack->val;
}

int 	get_min(t_stack *stk)
{
	int min;

	min = stk->val;
	while (stk)
	{
		if (stk->val < min)
			min = stk->val;
		stk = stk->next;
	}
	return min;
}

int 	get_max(t_stack *stk)
{
	int max;

	max = stk->val;
	while (stk)
	{
		if (stk->val > max)
			max = stk->val;
		stk = stk->next;
	}
	return max;
}

int 	get_move(int val, t_stack *b)
{
	int 	move;
	int 	size;
	int 	prev;
	t_stack *start;
	int 	min;
	int 	max;

	min = get_min(b);
	max = get_max(b);
	start = b;
	size = stack_size(b);
	move = 0;
	prev = stack_get(b, size - 1);
	//printf("prev: %i\tcurr: %i\tnext: %i\n", prev, val, b->val);
	while (!(val > b->val && val < prev))
	{
		if ((b->val == min && val < min) || (b->val == max && val > max))
		{
			if (b->val == min && val < min)
				move++;
			break;
		}
		move++;
		if (b->val == min && val < min)
			break;
		prev = b->val;
		if (b->next)
			b = b->next;
		else
			b = start;
		//printf("prev: %i\tcurr: %i\tnext: %i\n", prev, val, b->val);
	}
	if (move > size / 2)
		move = (size - move) * -1;
	//printf("move: %i\n", move);
	return (move);
}

void	make_move(t_stack **stk, int move)
{
	if (move < 0)
	{
		while (move++)
			revr('b', stk);
	}
	else
	{
		while (move--)
			r('b', stk);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	//printf("sort start\n");
	while (*a)
	{
		//pstacks(*a, *b);
		make_move(b, get_move((*a)->val, *b));
		push('b', b, a);
	}
	//pstacks(*a, *b);
}