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

int 	get_move(int val, t_stack *b)
{
	int move;
	int size;
	int prev;

	size = stack_size(b);
	move = 0;
	prev = stack_get(b, size);
	while (val < b->val)
	{
		move++;
		b = b->next;
	}
}

void	sort(t_stack **a, t_stack **b)
{

}