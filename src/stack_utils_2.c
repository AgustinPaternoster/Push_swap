#include "../include/push_swap.h"

t_stack	*find_highest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*higest;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	higest = *stack;
	while (tmp->next != NULL)
	{
		if (higest->idx < tmp->next->idx)
			higest = tmp->next;
		tmp = tmp->next;
	}
	return (higest);
}

t_stack	*find_lowest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*lowest;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	lowest = *stack;
	while (tmp->next != NULL)
	{
		if (lowest->idx > tmp->next->idx)
			lowest = tmp->next;
		tmp = tmp->next;
	}
	return (lowest);
}

t_stack	*find_last_node(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	len_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
