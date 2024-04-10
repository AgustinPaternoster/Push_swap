#include "../include/push_swap.h"



void tiny_sort(t_stack **stack)
{
	if (find_lowest(stack) == *stack)
	{
		ft_sa(stack);
		ft_ra(stack);
		return;
	}	
	if (find_highest(stack) == *stack)
	{
		ft_ra(stack);
		if (!check_sort(stack))
			ft_sa(stack);
		return;
	}
	else
	{
		if (find_node(stack,2) == find_highest(stack))
			ft_rra(stack);
		else
			ft_sa(stack);	
	}
	
}

