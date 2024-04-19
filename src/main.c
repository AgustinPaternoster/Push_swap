#include "../include/push_swap.h"

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	
	size = len_stack(stack_a);
    if (check_sort(stack_a))
        return;
	if (size < 4 )
		tiny_sort(stack_a);
	else
		large_sort(stack_a,stack_b);
}

bool init_stack(t_stack **stack_A, char **argv , int arg)
{
    int i;
    long nb;
    t_stack *new_node;

    i = 0;
    while (i < arg)
    {
        if (!check_int(argv[i]))
            return (free_stack(stack_A),false);
        nb = ft_atol(argv[i]);
        if(nb > INT_MAX || nb < INT_MIN)
            return (free_stack(stack_A),false);
        new_node = create_node(nb);
        if (!new_node)
            return (free_stack(stack_A),false);
        add_stack(stack_A,new_node);
        i++;
    }
    if (check_dup(stack_A))
        return (free_stack(stack_A),false);
    if(!set_idx(stack_A))
        return (free_stack(stack_A),false);
    set_stack_pos(stack_A);
    return (true);
}

int main(int arg, char **argv)
{
    t_stack *stack_A;
    t_stack *stack_B;
	t_stack *target;

    stack_A = NULL;
    stack_B = NULL;

    if (arg == 1)
        return(ft_printf("Error\n"),0);
    
	if(!init_stack(&stack_A, argv + 1 ,arg - 1))
		 write(1,"Error\n",6);
    sort_stack(&stack_A, &stack_B);
    printstact(&stack_A);
	return (0);
}
