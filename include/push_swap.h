#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <unistd.h>
#include <stdlib.h>
#include "../printf/ft_printf.h"
#include <limits.h>

typedef struct l_stack 
{
    int idx;
    int nb;
	int position;
    struct l_stack *prev;
    struct l_stack *next;
}t_stack;

//ft_utils
long ft_atol(char *str);
int ft_isdigit(char c);
int ft_strlen(char *str);
int ft_isspace(char c);
int find_idx(int nb,int *stack);

//ft_stack
t_stack *create_node(int nb);
void printstact(t_stack ** stack);
void add_stack(t_stack ** stack,t_stack *node);
int *ft_stack_c(t_stack **stack_a, int size);
void quick_sort(int *a,int lenght);
t_stack *last_node(t_stack **stack);
int len_stack(t_stack **stack);
void free_stack(t_stack **stack);
void set_stack_pos(t_stack **stack);
int check_sort(t_stack **stack);
void sort_stack(t_stack **stack_a, t_stack **stack_b);
int set_idx(t_stack **stack_a);
int get_idx(t_stack **stack, int pos);
int check_sort(t_stack **stack);
t_stack *find_highest(t_stack **stack);
//movements
void push(t_stack ** dst , t_stack ** src);
void ft_pa(t_stack ** stack_a , t_stack ** stack_b);
void ft_pb(t_stack ** stack_a , t_stack ** stack_b);
void ft_sa(t_stack **stack_a);
void ft_sb(t_stack **stack_b);
void ft_ss(t_stack **stack_a, t_stack **stack_b);
void ft_ra(t_stack **stack_a);
void ft_rb(t_stack **stack_b);
void ft_rr(t_stack **stack_a, t_stack **stack_b);
void ft_rra(t_stack **stack_a);
void ft_rrb(t_stack **stack_b);
void ft_rrr(t_stack **stack_a, t_stack **stack_b);
//errors
int check_int(char *str);
int check_dup(t_stack **stack_a);
#endif
