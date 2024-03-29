#include "push_swap.h"

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

void add_stack(t_stack **stack, t_stack *node)
{
    t_stack *tmp;
    t_stack *last_node;

    tmp = *stack;
    if(tmp == NULL)
    {
        *stack = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        last_node = tmp->prev;
        last_node->next = node;
        tmp->prev = node;
        node->next = tmp;
        node->prev = last_node;
    }

}

void printstact(t_stack ** stack)
{
	t_stack * tmp;
	t_stack *firstnode;
	
	firstnode = *stack;
	tmp = firstnode; 
	do
	{
		printf("nb:%d , idx:%d\n",tmp->nb , tmp->idx);
		tmp = tmp->next;;
	}
	while (tmp != firstnode);
}
