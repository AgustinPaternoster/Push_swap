#include "../include/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = len_stack(stack_a);
	if (check_sort(stack_a))
		return ;
	else if (size < 4)
		tiny_sort(stack_a);
	else
		large_sort(stack_a, stack_b);
}

bool	init_stack(t_stack **stack_a, char **argv, int arg)
{
	int		i;
	long	nb;
	t_stack	*new_node;

	i = 0;
	while (i < arg)
	{
		if (!check_int(argv[i]))
			return (free_stack(stack_a), false);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (free_stack(stack_a), false);
		new_node = create_node(nb);
		if (!new_node)
			return (free_stack(stack_a), false);
		add_stack(stack_a, new_node);
		i++;
	}
	if (check_dup(stack_a))
		return (free_stack(stack_a), false);
	if (!set_idx(stack_a))
		return (free_stack(stack_a), false);
	set_stack_pos(stack_a);
	return (true);
}

int	main(int arg, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (arg == 1)
		return (ft_printf("Error\n"), 0);
	if (!init_stack(&stack_a, argv + 1, arg - 1))
		return (ft_printf("Error\n"), free(stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
