#include "../include/push_swap.h"

t_stack *create_node(int nb)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->nb = nb;
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


void free_stack(t_stack **stack)
{
	t_stack *tmp;
	t_stack *node;

	node = *stack;
	while(node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

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


