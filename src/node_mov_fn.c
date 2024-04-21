#include "../include/push_swap.h"

void	send_to_top_b(t_stack **stack, t_stack *target)
{
	while (*stack != target)
	{
		if (target->above_median == true)
			ft_rb(stack);
		else
			ft_rrb(stack);
	}
}

void	send_to_top_a(t_stack **stack, t_stack *target)
{
	while (*stack != target)
	{
		if (target->above_median == true)
			ft_ra(stack);
		else
			ft_rra(stack);
	}
}

void	node_movements_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*costless;
	t_stack	*target;

	costless = find_costless_node(stack_a);
	target = find_closer_smll(stack_b, costless->idx);
	if (costless->above_median == target->above_median)
	{
		while (*stack_a != costless && *stack_b != target)
		{
			if (costless->above_median == true)
				ft_rr(stack_a, stack_b);
			else
				ft_rrr(stack_a, stack_b);
		}
		send_to_top_a(stack_a, costless);
		send_to_top_b(stack_b, target);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		send_to_top_a(stack_a, costless);
		send_to_top_b(stack_b, target);
		ft_pb(stack_a, stack_b);
	}
}

void	node_movements_b(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	t_stack	*target;

	target = find_closer_big(stack_a, node->idx);
	if (node->above_median == target->above_median)
	{
		while (*stack_b != node && *stack_a != target)
		{
			if (node->above_median == true)
				ft_rr(stack_a, stack_b);
			else
				ft_rrr(stack_a, stack_b);
		}
		send_to_top_b(stack_b, node);
		send_to_top_a(stack_a, target);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		send_to_top_b(stack_b, node);
		send_to_top_a(stack_a, target);
		ft_pa(stack_a, stack_b);
	}
}
