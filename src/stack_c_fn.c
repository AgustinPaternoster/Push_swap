/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_c_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:08:05 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:08:07 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	*ft_stack_c(t_stack **stack_a, int size)
{
	t_stack	*tmp;
	int		*stack;
	int		i;
	
	if (stack_a == NULL)
		return (NULL);
	stack = malloc (sizeof(int) * size);
	if (!stack)
		return (NULL);
	i = 0;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		stack[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	return (stack);
}

int	find_idx(int nb, int *stack)
{
	int	i;
	
	if (stack == NULL)
		return (0);
	i = 0;
	while (stack[i] != nb)
		i++;
	return (i + 1);
}
