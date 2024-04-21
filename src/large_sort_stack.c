#include "../include/push_swap.h"

void large_sort(t_stack **stack_a, t_stack **stack_b)
{
    if (len_stack(stack_a) > 3)
        ft_pb(stack_a,stack_b);
    if (len_stack(stack_a) > 3)
        ft_pb(stack_a,stack_b);
    while(len_stack(stack_a) > 3)
    {
        cost_calculation_a(stack_a,stack_b);
        node_movements_a(stack_a,stack_b);
    }
    if (!check_sort(stack_a))
        tiny_sort(stack_a);
    while(*stack_b !=NULL)
    {
        //cost_calculation_b(stack_a,stack_b);
        node_movements_b(stack_a,stack_b,*stack_b);
    }
    send_to_top_a(stack_a,find_lowest(stack_a));
    return;
}