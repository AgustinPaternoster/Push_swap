/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:13:49 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/19 11:14:35 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct l_stack
{
	int				idx;
	int				nb;
	int				position;
	int				cost;
	bool			above_median;
	struct l_stack	*prev;
	struct l_stack	*next;
}	t_stack;

//ft_utils
long	ft_atol(char *str);
int		ft_isdigit(char c);
int		ft_strlen(char *str);
int		ft_isspace(char c);
int		find_idx(int nb, int *stack);
char	**ft_split(char *str);
void	ft_putstr_fd(char *s, int fd);

//ft_stack
t_stack	*create_node(int nb);
void	printstact(t_stack **stack);
void	add_stack(t_stack **stack, t_stack *node);
int		*ft_stack_c(t_stack **stack_a, int size);
void	quick_sort(int *a, int lenght);
t_stack	*find_last_node(t_stack **stack);
int		len_stack(t_stack **stack);
void	free_stack(t_stack **stack);
void	set_stack_pos(t_stack **stack);
int		set_idx(t_stack **stack_a);
//int get_idx(t_stack **stack, int pos);
bool	check_sort(t_stack **stack);
t_stack	*find_highest(t_stack **stack);
t_stack	*find_lowest(t_stack **stack);
t_stack	*find_node_bypos(t_stack **stack, int pos);
t_stack	*find_node_byidx(t_stack **stack, int idx);
t_stack	*find_closer_big(t_stack **stack, int idx);
t_stack	*find_closer_smll(t_stack **stack, int idx);
int		count_mov(t_stack **stack, t_stack *target);
void	cost_calculation_a(t_stack **stack_a, t_stack **stack_b);
void	cost_calculation_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_costless_node(t_stack **stack_a);
//node movements
void	send_to_top_a(t_stack **stack, t_stack *target);
void	send_to_top_b(t_stack **stack, t_stack *target);
void	node_movements_a(t_stack **stack_a, t_stack **stack_b);
void	node_movements_b(t_stack **stack_a, t_stack **stack_b, t_stack *node);
//algorithm
void	tiny_sort(t_stack **stack);
void	large_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
//subject movements
void	push(t_stack **dst, t_stack **src);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
//errors
bool	check_int(char *str);
bool	check_dup(t_stack **stack_a);
#endif
