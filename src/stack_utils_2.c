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

t_stack *find_lowest(t_stack **stack)
{
    t_stack *tmp;
	t_stack *lowest;

	tmp = *stack;
	lowest = *stack;
	while(tmp->next != NULL)
	{
		if (lowest->idx > tmp->next->idx)
			lowest = tmp->next;
		tmp = tmp->next;
	}
	return (lowest);
}

