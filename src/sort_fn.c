#include "../include/push_swap.h"

int count_mov(t_stack **stack , t_stack *target)
{
    int mov;
    t_stack *lastnode;

    mov = 0;
    lastnode = find_last_node(stack);
    if(target->above_median == true)
    {
        mov = target->position - 1;
    }
    else
    {
        mov = lastnode->position - target->position + 1;
    }
    return (mov);
}