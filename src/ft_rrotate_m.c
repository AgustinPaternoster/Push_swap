#include "../include/push_swap.h"

void rrotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *lastnode;

    tmp = *stack;
    lastnode = last_node(stack);
    if(!tmp->next)
        return;
    *stack = lastnode;
    lastnode->prev->next = NULL;
    tmp->prev = lastnode;
    lastnode->prev = NULL;
    lastnode->next = tmp;
}

void ft_rra(t_stack **stack_a)
{
    if(!*stack_a)
        return;
    rrotate(stack_a);
}

void ft_rrb(t_stack **stack_b)
{
    if(!*stack_b)
        return;
    rrotate(stack_b);
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
}