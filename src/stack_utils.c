#include "../include/push_swap.h"

int len_stack(t_stack **stack)
{
	t_stack *tmp;
	int i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void printstact(t_stack ** stack)
{
	t_stack *tmp;

	
	tmp = *stack;
	if(!tmp)
		ft_printf("NULL\n");
	while (tmp != NULL)
	{
		ft_printf("nb: %d idx: %d pos: %d\n", tmp->nb, tmp->idx, tmp->position);
		tmp = tmp->next;
	}
}

void set_stack_pos(t_stack **stack)
{
	int i;
	t_stack *tmp;

	tmp = *stack;
	i = 1;
	while(tmp !=NULL)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

t_stack *find_node(t_stack **stack, int pos)
{
	t_stack *tmp;

	tmp = *stack;
	while(tmp != NULL)
	{
		if(tmp->position == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

// int get_idx(t_stack **stack, int pos)
// {
// 	t_stack *tmp;
// 	int idx;

// 	tmp = *stack;
// 	while(tmp != NULL)
// 	{
// 		if (tmp->position == pos)
// 			return (tmp->idx);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
int check_sort(t_stack **stack)
{
	int check;
	t_stack *node;
	t_stack *tmp;
	
	node = *stack;
	while(node != NULL)
	{
		tmp = node->next;
		while(tmp != NULL)
		{
			if(node->idx > tmp->idx)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}