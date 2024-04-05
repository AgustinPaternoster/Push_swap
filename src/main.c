#include "../include/push_swap.h"

void get_idx(t_stack **stack_a)
{
    t_stack *tmp;
    int i;
    int stack_c[len_stack(stack_a)];
  
    tmp = *stack_a;
    i = 0;
    while(tmp != NULL)
    {
        stack_c[i] = tmp->nb;
        tmp = tmp->next;
        i++;
    }
    counting_sort(stack_c , i +1 );
    tmp = *stack_a;
    while(tmp != NULL)
    {
        tmp->idx = find_idx(tmp->nb,stack_c);
        tmp = tmp->next;
    }
}

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
    get_idx(stack_A);
    return (1);
}

int main(int arg, char **argv)
{
    t_stack *stack_A;
    t_stack *stack_B;

    stack_A = NULL;
    stack_B = NULL;

    if (arg == 1)
        return(ft_printf("Error\n"),0);
    
	if(!start(&stack_A,argv,arg))
		 write(1,"Error\n",6);
    printstact(&stack_A);
	return (0);
}
