#include "../include/push_swap.h"

long ft_atoi(char *str)
{
    int i;
    long nb;
    int sign;

    sign = 1;
    nb = 0;
	i = 0;
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

int ft_isdigit(char c)
{ 
    if(c > 47 && c < 58 || c == 43 || c == 45)
        return (1);
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}