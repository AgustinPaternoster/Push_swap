#include "../include/push_swap.h"

void send_to_top_a(t_stack **stack , t_stack *target)
{
    while (*stack != target)
    {
        if (target->above_median == true)
            ft_ra(stack);
        else
            ft_rra(stack);
    }
}

void finish_sort(t_stack **stack_a , t_stack **stack_b)
{
    t_stack *target_node;

    if (find_highest(stack_b) != *stack_b)
        ft_rb(stack_b);
    while(*stack_b !=NULL)
    {
        target_node = find_closer_big(stack_a,(*stack_b)->idx);
        send_to_top_a(stack_a,target_node);
        ft_pa(stack_a,stack_b);
    }
    target_node = find_lowest(stack_a);
    send_to_top_a(stack_a,target_node);
}

void large_sort(t_stack **stack_a, t_stack **stack_b)
{
;
    if (len_stack(stack_a) > 3)
        ft_pb(stack_a,stack_b);
    if (len_stack(stack_a) > 3)
        ft_pb(stack_a,stack_b);
    while(len_stack(stack_a) > 3)
    {

    }
    if (!check_sort(stack_a))
        tiny_sort(stack_a);
    finish_sort(stack_a,stack_b);
    return;
}