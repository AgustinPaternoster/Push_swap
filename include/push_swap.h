#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <unistd.h>
#include <stdlib.h>
#include "../printf/ft_printf.h"

typedef struct l_stack 
{
    int idx;
    int nb;
    struct l_stack *prev;
    struct l_stack *next;
}t_stack;

int ft_atoi(char *str);
t_stack *create_node(int nb);
void printstact(t_stack ** stack);
void add_stack(t_stack ** stack,t_stack *node);
void del_first_node(t_stack ** stack);
void ft_pa(t_stack ** stack_a , t_stack ** stack_b);
#endif
