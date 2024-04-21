#include "../include/push_swap.h"

void swap(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    if(!tmp->next)
        return;
    *stack = tmp->next;
    (*stack)->prev = NULL;
    tmp->next = (*stack)->next;
    (*stack)->next->prev = tmp;
    (*stack)->next = tmp;
    tmp->prev = *stack;
    set_stack_pos(stack);
}

void ft_sa(t_stack **stack_a)
{
    if (!*stack_a)
        return;
    swap(stack_a);
    ft_printf("sa\n");
}

void ft_sb(t_stack **stack_b)
{
    if (!*stack_b)
        return;
    swap(stack_b);
    ft_printf("sa\n");
}

void ft_ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
}