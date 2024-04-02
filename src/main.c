#include "../include/push_swap.h"

int start(t_stack **stack_A, char **argv , int arg)
{
    int i;
	int nb;
    t_stack *new_node;

    i = 1;
    while (i < arg)
    {
        nb = ft_atoi(argv[i]);
		new_node = create_node(nb);
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

    stack_A = NULL;
    stack_B = NULL;

	 if(!start(&stack_A,argv,arg))
		 write(1,"Error\n",6);
	
	printstact(&stack_A);
    return (0);
}
