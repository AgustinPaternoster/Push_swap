#include "push_swap.h"

int atoi(char *str)
{
    int i;
    int nb;
    int sign;

    sign = 1;
    nb = 0;
    if(str[0] == 45 | str[0] == 43)
    {
        if(str[0] == 45)
            sign = -1;
        i++;
    }
    while(str[i])
    {
        nb *= 10;
		nb += str[i] - 48;
        i++;
    }
    return (nb * sign);
}
