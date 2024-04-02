#include "../include/push_swap.h"

void ft_pa(t_stack ** stack_a , t_stack ** stack_b)
{
	t_stack *tmp;
	if(!stack_a)
		return;
	tmp = *stack_a,
	del_first_node(stack_a);
	add_stack(stack_b,tmp);
}

void ft_pb(t_stack ** stack_a , t_stack ** stack_b)
{
	t_stack *tmp;
	if(!stack_a)
		return;
	tmp = *stack_a,
	del_first_node(stack_a);
	add_stack(stack_b,tmp);
}