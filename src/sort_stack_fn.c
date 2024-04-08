#include "../include/push_swap.h"

void tiny_sort(t_stack **stack)
{
	return;
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	

	size = len_stack(stack_a);
	if (size < 4 )
		tiny_sort(stack_a);
	else
		return;
}
