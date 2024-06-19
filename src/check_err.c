/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:03:46 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:03:52 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_dup(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack_a;
	while (node != NULL)
	{
		tmp = node->next;
		while (tmp != NULL)
		{
			if (node->nb == tmp->nb)
				return (true);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (false);
}
