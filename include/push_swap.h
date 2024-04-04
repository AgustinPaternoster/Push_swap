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
    struct l_stack *prev;
    struct l_stack *next;
}t_stack;

//ft_utils
long ft_atoi(char *str);
int ft_isdigit(char c);
int ft_strlen(char *str);
//ft_stack
t_stack *create_node(int nb, int idx);
void printstact(t_stack ** stack);
void add_stack(t_stack ** stack,t_stack *node);
int  *create_stack_C(char **argv , int arg);
void counting_sort(int *a, int length);
int find_idx(int nb,int *stack , int len);
t_stack *last_node(t_stack **stack);
int len_stack(t_stack **stack);
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
int check_err(int arc, char **argv);
int check_dup(int arc, char **argv);


#endif
