/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:43 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:10:59 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_stack(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;
	t_stack	*lastnode;

	if (stack == NULL)
		return ;
	tmp = *stack;
	if (!tmp)
		*stack = node;
	else
	{
		lastnode = find_last_node(stack);
		lastnode->next = node;
		node->prev = lastnode;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	if (stack == NULL)
		return ;
	node = *stack;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

int	set_idx(t_stack **stack_a)
{
	t_stack	*tmp;
	int		*stack_c;
	int		size;

	if (stack_a == NULL)
		return (0);
	size = len_stack(stack_a);
	tmp = *stack_a;
	stack_c = ft_stack_c(stack_a, size);
	if (!stack_c)
		return (0);
	quick_sort(stack_c, size);
	while (tmp != NULL)
	{
		tmp->idx = find_idx(tmp->nb, stack_c);
		tmp = tmp->next;
	}
	free(stack_c);
	return (1);
}
