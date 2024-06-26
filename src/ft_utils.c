/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:04:34 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:04:38 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	nb;
	int		sign;

	if (str == NULL)
		return (0);
	sign = 1;
	nb = 0;
	i = 0;
	if ((str[0] == 45) || (str[0] == 43))
	{
		if (str[0] == 45)
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}

int	ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == 32 || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}
