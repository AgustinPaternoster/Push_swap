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

void add_stack(t_stack ** stack,t_stack *node)
{
	t_stack *tmp;
	t_stack *lastnode;

	tmp = *stack;
	if(!tmp)
		*stack = node;
	else
	{
		lastnode = find_last_node(stack);
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

int set_idx(t_stack **stack_a)
{
    t_stack *tmp;
    int *stack_c;
    int size;

    size = len_stack(stack_a);
    tmp = *stack_a;
    stack_c = ft_stack_c(stack_a, size);
    if (!stack_c)
        return (0);
    quick_sort(stack_c , size);
    while(tmp != NULL)
    {
        tmp->idx = find_idx(tmp->nb,stack_c);
        tmp = tmp->next;
    }
    return (1);
}