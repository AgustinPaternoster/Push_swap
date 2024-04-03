#include "../include/push_swap.h"

int  *create_stack_C(char **argv , int arg)
{
	int *stack_c;
	int size;
	int i;

	size = arg -1;
	stack_c = malloc(sizeof(int) * size);
    if (!stack_c)
        return (NULL);
	i = 1;
	while(i < arg)
	{
		stack_c[i-1] = ft_atoi(argv[i]);
		i++;
	}
    counting_sort(stack_c,size);
	return (stack_c);
}

int find_idx(int nb,int *stack , int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if(nb == stack[i])
            return (i + 1);
        i++;
    }
}
