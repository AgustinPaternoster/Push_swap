#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <unistd.h>
#include <stdlib.h>

/////////////////
#include <stdio.h>
//////////////////
typedef struct l_stack 
{
    int idx;
    int nb;
    struct l_stack *prev;
    struct l_stack *next;
}t_stack;

int ft_atoi(char *str);
t_stack *create_node(int nb, int idx);
void add_stack(t_stack **stack, t_stack *node);
void printstact(t_stack ** stack);
#endif
