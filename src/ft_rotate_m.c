#include "../include/push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *lastnode;
    t_stack *tmp;

    tmp = *stack;
    lastnode = last_node(stack);
    if (!tmp->next)
        return;
    *stack = tmp->next;
    (*stack)->prev = NULL;
    lastnode->next = tmp;
    tmp->prev = lastnode;
    tmp->next = NULL;
    set_stack_pos(stack);
}

void ft_ra(t_stack **stack_a)
{
    if(!*stack_a)
        return;
    rotate(stack_a);
    ft_printf("ra\n");
}

void ft_rb(t_stack **stack_b)
{
    if(!*stack_b)
        return;
    rotate(stack_b);
    ft_printf("rb\n");
}

void ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    ft_ra(stack_a);
    ft_rb(stack_b);
    ft_printf("rr\n");
}