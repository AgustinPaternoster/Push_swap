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