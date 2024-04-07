#include "../include/push_swap.h"

int check_int(char * str)
{
    int i;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == 43 || str[i] == 45)
        i++;
    while (str[i])
    {  
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_dup(t_stack **stack_a)
{
   t_stack *node;
   t_stack *tmp;

   node = *stack_a;
   while(node != NULL)
   {
        tmp = node->next;
        while(tmp != NULL)
        {
            if (node->nb == tmp->nb)
                return (1);
            tmp = tmp->next;
        }
        node = node->next;
   }
   return (0);
}

