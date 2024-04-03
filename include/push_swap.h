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
t_stack *create_node(int nb, int idx);
void printstact(t_stack ** stack);
void add_stack(t_stack ** stack,t_stack *node);
int  *create_stack_C(char **argv , int arg);
void counting_sort(int *a, int length);
int find_idx(int nb,int *stack , int len);
#endif
