#include "../include/push_swap.h"

t_stack *find_highest(t_stack **stack)
{
	t_stack *tmp;
	t_stack *higest;

	tmp = *stack;
	higest = *stack;
	while(tmp->next != NULL)
	{
		if (higest->idx < tmp->next->idx)
			higest = tmp->next;
		tmp = tmp->next;
	}
	return (higest);
}

void tiny_sort(t_stack **stack)
{
	
	return;
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	
	size = len_stack(stack_a);
    if (check_sort(stack_a))
        return;
	if (size < 4 )
		tiny_sort(stack_a);
	else
		return;
}
