#include "../include/push_swap.h"

void finish_sort(t_stack **stack_a , t_stack **stack_b)
{
    t_stack *target_node;

    // if (find_highest(stack_b) != *stack_b)
    //     ft_rb(stack_b);
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
        cost_calculation(stack_a,stack_b);
        node_movements(stack_a,stack_b);

    }
    if (!check_sort(stack_a))
        tiny_sort(stack_a);
    finish_sort(stack_a,stack_b);
    return;
}