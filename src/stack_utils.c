#include "../include/push_swap.h"

void	set_stack_pos(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	int		len;

	if (stack == NULL)
		return (NULL);
	len = len_stack(stack);
	tmp = *stack;
	i = 1;
	while (tmp != NULL)
	{
		tmp->position = i;
		if ((len / 2) >= i)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		i++;
	}
}

t_stack	*find_node_bypos(t_stack **stack, int pos)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->position == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*find_closer_big(t_stack **stack, int idx)
{
	t_stack	*tmp;
	int		idx_obj;
	int		idx_higest;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	idx_obj = idx + 1;
	idx_higest = (find_highest(stack))->idx;
	while (idx_obj <= idx_higest)
	{
		while (tmp != NULL)
		{
			if (tmp->idx == idx_obj)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = *stack;
		idx_obj++;
	}
	return (find_lowest(stack));
}

t_stack	*find_closer_smll(t_stack **stack, int idx)
{
	t_stack	*tmp;
	int		idx_obj;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	idx_obj = idx - 1;
	while (idx_obj >= 1)
	{
		while (tmp != NULL)
		{
			if (tmp->idx == idx_obj)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = *stack;
		idx_obj--;
	}
	return (find_highest(stack));
}

bool	check_sort(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	if (stack == NULL)
		return (NULL);
	node = *stack;
	while (node != NULL)
	{
		tmp = node->next;
		while (tmp != NULL)
		{
			if (node->idx > tmp->idx)
				return (false);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (true);
}
