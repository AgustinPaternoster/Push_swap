#include "../include/push_swap.h"



void push(t_stack ** dst , t_stack ** src)
{
	t_stack *node_to_move;

	node_to_move = *src;
	*src = node_to_move->next;
	if(*src != NULL)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_move;
		node_to_move->next = NULL;
	}
	else
	{
		(*dst)->prev = node_to_move;
		node_to_move->next = *dst;
		*dst = node_to_move;
	}
	set_stack_pos(src);
	set_stack_pos(dst);
}

void ft_pa(t_stack ** stack_a , t_stack ** stack_b)
{
	if(!*stack_a)
		return;
	push(stack_a,stack_b);
	ft_printf("pa\n");
}

void ft_pb(t_stack ** stack_a , t_stack ** stack_b)
{
	if(!*stack_a)
		return;
	push(stack_b,stack_a);
	ft_printf("pb\n");
}
