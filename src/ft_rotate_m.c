#include "../include/push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *lastnode;
    t_stack *tmp;

    tmp = *stack;
    lastnode = last_node(stack);
    if (!tmp->next)
        return;
    
}