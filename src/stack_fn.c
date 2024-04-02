#include "../include/push_swap.h"

t_stack *create_node(int nb)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->nb = nb;
    node->idx = 0;
    node->next = NULL;
    node->prev = NULL;
	return(node);
}

void printstact(t_stack ** stack)
{
	t_stack * tmp;
	t_stack *firstnode;
	
	firstnode = *stack;
	tmp = firstnode; 
	do
	{
		ft_printf("nb:%d , idx:%d\n",tmp->nb , tmp->idx);
		tmp = tmp->next;;
	}
	while (tmp != firstnode);
}

void add_stack(t_stack ** stack,t_stack *node)
{
	t_stack *tmp;
	t_stack *lastnode;

	tmp  = *stack;
	if (!tmp)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
		node->idx = 1;
	}
	else
	{
		lastnode = tmp->prev;	
		node->idx = lastnode->idx + 1;
		node->prev = lastnode;
		node->next = tmp;
		lastnode->next = node;
		tmp->prev = node;
	}
}

void correct_idx(t_stack *lastnode)
{
	t_stack *tmp;
	int i;
	int newidx;

	tmp = lastnode->prev;
	i = 1;
	newidx = lastnode->idx - 1;
	while( i <= newidx)
	{
		tmp->idx = i;
		tmp = tmp->next;
		i++;
	}	
	
}

void del_first_node(t_stack ** stack)
{
	t_stack *tmp;
	t_stack *new_first_node;
	t_stack *last_node;

	tmp = *stack;
	if(!tmp)
		return;
	if (tmp->next == tmp->prev)
		*stack = NULL;
	else
	{
		new_first_node = tmp->next;
		last_node = tmp->prev;
		new_first_node->prev = last_node;
		last_node->next = new_first_node;
		correct_idx(last_node);
		*stack = new_first_node;
	}
}
