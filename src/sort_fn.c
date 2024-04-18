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

void cost_calculation(t_stack **stack_a , t_stack **stack_b)
{
    t_stack *node;
    t_stack *target;
    int cost;

    node = *stack_a;
    while (node != NULL)
    {
        cost = 0;
        target = find_closer_smll(stack_b,node->idx);
        if (target->above_median == node->above_median)
        {
            cost = count_mov(stack_a,node);
            if (count_mov(stack_b,target) > cost)
                cost = count_mov(stack_b,target);
        }
        else
        {
            cost = count_mov(stack_a,node) + count_mov(stack_b,target);
        }
        node->cost = cost;
        node = node->next;
    }
}