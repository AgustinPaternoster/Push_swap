#include "../include/push_swap.h"

int check_limits(char *str)
{
    long nb;
    static int chk;

    nb = ft_atol(str);
    if(nb > INT_MAX || nb < INT_MIN)
        return (0);
    return(1);
}

int check_int(char * str)
{
    int i;
    int chksign;
    
    i = 0;
    chksign = 0;
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        if(str[i] == 43 || str[i] == 45)
            chksign++;
        i++;
    }
    if (chksign > 1)
        return (0);
    return (1);
}

int check_dup(int arc, char **argv)
{
    int i;
    int k;
    int size;
    int arr[arc - 1];

    size = arc - 1;
    i = 1;
    while (i < arc)
        {
            arr[i - 1] = ft_atol(argv[i]);
            i++;
        }
    i = 0;
    while(i < size)
    {
        k = 1 + i;
        while (k < size)
        {
            if(arr[i] == arr[k])
                return (0);
            k++;
        }
        i++;
    }
    return (1);
}

int check_err(int arc, char **argv)
{
    int i;

    i = 1;
    while( i < arc)
    {
        if(!check_int(argv[i]))
            return (0);
        if(!check_limits(argv[i]))
            return(0);
        i++;
    }
    if (!check_dup(arc,argv))
        return (0);
    return(1);
}