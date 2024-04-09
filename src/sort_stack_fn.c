#include "../include/push_swap.h"



void tiny_sort(t_stack **stack)
{
	if (find_lowest(stack) == *stack)
	{
		ft_sa(stack);
		ft_ra(stack);
	}	
	if (find_highest(stack) == *stack)
	{
		ft_ra(stack);
		if (!check_sort(stack))
			ft_sa(stack);
	}
	else
	{
		if (find_node(stack,2) == find_highest(stack))
			ft_rra(stack);
		else;
			ft_sa;	
	}
	
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
