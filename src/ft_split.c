/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:09:15 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:09:18 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lenstr(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
		i++;
	return (i);
}

int	sizeofarray(char *str)
{
	int	i;
	int	count;

	i = 0;
	if (str[i] == '\0' || !str)
		return (1);
	count = 1;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 10 || str[i] == 9)
			count++;
		i++;
	}
	return (count + 1);
}

char	*cpystr(int *pos, char *str)
{
	int		i;
	char	*result;
	int		size;
	int		j;

	i = *pos;
	j = 0;
	while ((str[i] == 32 || str[i] == 10 || str[i] == 9))
		i++;
	size = ft_lenstr(str + i);
	result = malloc(sizeof(char) * size + 1);
	if (!result || !str)
		return (NULL);
	while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	*pos = i;
	return (result);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		size;
	int		pos;

	if (!str)
		return (NULL);
	pos = 0;
	size = sizeofarray(str);
	result = malloc(sizeof(char *) * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		result[i] = cpystr(&pos, str);
		if (!result)
			return (NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
