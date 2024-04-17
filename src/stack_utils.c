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
		ft_printf("nb: %d idx: %d pos: %d med:%d\n", tmp->nb, tmp->idx, tmp->position , tmp->above_median);
		tmp = tmp->next;
	}
}

void set_stack_pos(t_stack **stack)
{
	int i;
	t_stack *tmp;
	int len;

	len = len_stack(stack);
	tmp = *stack;
	i = 1;
	while(tmp !=NULL)
	{
		tmp->position = i;
		if ((len / 2) >=  i)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		i++;
	}

}

t_stack *find_node_bypos(t_stack **stack, int pos)
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


t_stack *find_closer_big(t_stack **stack, int idx)
{
	t_stack *tmp;
	int idx_obj;
	int idx_higest;

	tmp = *stack;
	idx_obj = idx + 1;
	idx_higest = (find_highest(stack))->idx;

	while (idx_obj <= idx_higest)
	{
		while( tmp !=NULL)
		{
			if (tmp->idx == idx_obj)
				return (tmp);
		tmp = tmp->next;
		}
		idx_obj++;
	}
	return(NULL);
}


// t_stack *find_node_byidx(t_stack **stack, int idx)
// {
// 	t_stack *tmp;

// 	tmp = *stack;
// 	while( tmp !=NULL)
// 	{
// 		if (tmp->idx == idx)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return(NULL);
// }

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
bool check_sort(t_stack **stack)
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
				return (false);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (true);
}