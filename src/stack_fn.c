#include "../include/push_swap.h"

t_stack *create_node(int nb, int idx)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->nb = nb;
    node->idx = idx;
    node->next = NULL;
    node->prev = NULL;
	return(node);
}

t_stack *last_node(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if(!tmp)
		return (NULL);
	while(tmp->next != NULL)
		tmp = tmp->next;
	return(tmp);
}

void printstact(t_stack ** stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		ft_printf("nb: %d idx: %d\n", tmp->nb, tmp->idx);
		tmp = tmp->next;
	}
}

void add_stack(t_stack ** stack,t_stack *node)
{
	t_stack *tmp;
	t_stack *lastnode;

	tmp = *stack;
	if(!tmp)
		*stack = node;
	else
	{
		lastnode = last_node(stack);
		lastnode->next = node;
		node->prev = lastnode;
	}
}
