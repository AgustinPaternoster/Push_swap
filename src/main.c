#include "../include/push_swap.h"

int start(t_stack **stack_A, char **argv , int arg)
{
    int i;
    int nb;
    int *stack_c;
    t_stack *new_node;

    stack_c = create_stack_C(argv,arg);
    if (!stack_c)
        return(0);
    i = 1;
    while (i < arg)
    {
		nb = ft_atoi(argv[i]);
        new_node = create_node(nb, find_idx(nb, stack_c, arg - 1));
        if (!new_node)
            return(0);
        add_stack(stack_A,new_node);
        i++;
    }
    return (1);
}

int main(int arg, char **argv)
{
    t_stack *stack_A;
    t_stack *stack_B;
    int *test;

    stack_A = NULL;
    stack_B = NULL;

	 if(!start(&stack_A,argv,arg))
		 write(1,"Error\n",6); 
    printstact(&stack_A);
    ft_pb(&stack_A,&stack_B);
    ft_pb(&stack_A,&stack_B);  
    ft_printf("---------\n");
    printstact(&stack_A);
    ft_printf("---------\n");
    printstact(&stack_B);
    ft_ss(&stack_A,&stack_B);
    ft_printf("---------\n");
    printstact(&stack_A);
    ft_printf("---------\n");
    printstact(&stack_B);

	return (0);
}
