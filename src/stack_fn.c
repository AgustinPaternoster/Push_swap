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
