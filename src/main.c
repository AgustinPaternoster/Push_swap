/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:09:33 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:09:37 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void cstk(char **stack)
{
	int i;

	i = 0;
	while (stack[i] != NULL)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (stack_a == NULL || stack_b == NULL)
		return ;
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
	while (i < arg || (argv[i] && arg == 1))
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
		return (ft_putstr_fd("Error\n", 2),0);
	if (arg == 2)
	{
		argv = ft_split(argv[1]);
		if (!init_stack(&stack_a, argv, arg - 1))
			return (ft_putstr_fd("Error\n", 2), free(stack_a),cstk(argv), 0);
		cstk(argv);
	}
	else
		if (!init_stack(&stack_a, argv + 1, arg - 1))
			return (ft_putstr_fd("Error\n", 2), free(stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}

// Muy buen proyecto, una pena que haya encontrado estos errores 
// tontos y ya sabes como solucionarlo y si necesitas ayuda aca me t
// ienes, a por todas y te dejo tanto el sanitize como los errores 
// encontrados . Un saludo :))) -fsanitize=leak Errores: - Norminette - 
// Leaks cuando pones solo un char/int - dar error cuando pasan "" - 
// Solucionar relink en printf (carpeta)