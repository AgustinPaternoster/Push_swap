/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:06 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:10:14 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_costless_node(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*node;
	int		cost;

	tmp = (*stack_a)->next;
	node = *stack_a;
	cost = node->cost;
	while (tmp != NULL)
	{
		if (cost > tmp->cost)
		{
			cost = tmp->cost;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

int	count_mov(t_stack **stack, t_stack *target)
{
	int		mov;
	t_stack	*lastnode;

	mov = 0;
	lastnode = find_last_node(stack);
	if (target->above_median == true)
	{
		mov = target->position - 1;
	}
	else
	{
		mov = lastnode->position - target->position + 1;
	}
	return (mov);
}

void	cost_calculation_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*target;
	int		cost;
	int		len_b;

	node = *stack_a;
	len_b = len_stack(stack_b);
	while (node != NULL)
	{
		cost = 0;
		target = find_closer_smll(stack_b, node->idx);
		if (target->above_median == node->above_median || len_b == 2)
		{
			cost = count_mov(stack_a, node);
			if (count_mov(stack_b, target) > cost)
				cost = count_mov(stack_b, target);
		}
		else
		{
			cost = count_mov(stack_a, node) + count_mov(stack_b, target);
		}
		node->cost = cost;
		node = node->next;
	}
}
