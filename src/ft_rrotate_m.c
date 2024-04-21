#include "../include/push_swap.h"

void rrotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *lastnode;

    tmp = *stack;
    lastnode = find_last_node(stack);
    if(!tmp->next)
        return;
    *stack = lastnode;
    lastnode->prev->next = NULL;
    tmp->prev = lastnode;
    lastnode->prev = NULL;
    lastnode->next = tmp;
    set_stack_pos(stack);
}

void ft_rra(t_stack **stack_a)
{
    if(!*stack_a)
        return;
    rrotate(stack_a);
    ft_printf("rra\n");
}

void ft_rrb(t_stack **stack_b)
{
    if(!*stack_b)
        return;
    rrotate(stack_b);
    ft_printf("rrb\n");
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    rrotate(stack_a);
    rrotate(stack_b);
    ft_printf("rrr\n");
}