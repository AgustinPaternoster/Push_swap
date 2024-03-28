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
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    return (nb * sign);
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    printf("%d\n", n);
}