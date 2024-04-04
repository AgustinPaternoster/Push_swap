#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
            arr[i - 1] = ft_atoi(argv[i]);
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

int main(int argc, char **argv) 
{
    int i = check_dup(argc, argv);
    printf("i :%d\n", i);
    return (0);
}