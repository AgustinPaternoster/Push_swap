#include "../include/push_swap.h"

int *ft_stack_c(t_stack **stack_a, int size)
{
    t_stack *tmp;
    int *stack;
    int i;

    stack = (int *)malloc(sizeof(int) * size);
    if (!stack)
        return (NULL);
    i = 0;
    tmp = *stack_a;
    while(tmp != NULL)
    {
        stack[i] = tmp->nb;
        tmp = tmp->next;
        i++;
    }
    return (stack);
}


int set_idx(t_stack **stack_a)
{
    t_stack *tmp;
    int *stack_c;
    int size;

    size = len_stack(stack_a);
    tmp = *stack_a;
    stack_c = ft_stack_c(stack_a, size);
    if (!stack_c)
        return (0);
    quick_sort(stack_c , size);
    while(tmp != NULL)
    {
        tmp->idx = find_idx(tmp->nb,stack_c);
        tmp = tmp->next;
    }
    return (1);
}

int init_stack(t_stack **stack_A, char **argv , int arg)
{
    int i;
    long nb;
    t_stack *new_node;

    i = 0;
    while (i < arg)
    {
        if (!check_int(argv[i]))
            return (free_stack(stack_A),0);
        nb = ft_atol(argv[i]);
        if(nb > INT_MAX || nb < INT_MIN)
            return (free_stack(stack_A),0);
        new_node = create_node(nb);
        if (!new_node)
            return (free_stack(stack_A),0);
        add_stack(stack_A,new_node);
        i++;
    }
    if (check_dup(stack_A))
        return (free_stack(stack_A),0);
    if(!set_idx(stack_A))
        return (free_stack(stack_A),0);
	set_stack_pos(stack_A);
    return (1);
}

int main(int arg, char **argv)
{
    t_stack *stack_A;
    t_stack *stack_B;
	t_stack *highest;

    stack_A = NULL;
    stack_B = NULL;

    if (arg == 1)
        return(ft_printf("Error\n"),0);
    
	if(!init_stack(&stack_A, argv + 1 ,arg - 1))
		 write(1,"Error\n",6);
	printstact(&stack_A);
	return (0);
}
