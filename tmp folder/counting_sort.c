#include "push_swap.h"
void count_aux(int *a,int len)
{
    int i;
    i = 1;
    while (i <= len)
    {
        a[i] += a[i-1];
        i++;
    }
}

int find_max(int *a , int length)
{
    int i;
    int max;

    max = 0;
    i = 0;
    while(i < length)
    {
        if (a[i] > max)
            max = a[i];
        i++;
    }
    return (max);
}

void cpy_arr(int *src, int *dst, int length)
{
    int i;

    i = 0;
    while (i < length)
    {
        dst[i] = src[i];
        i++;
    }
    
}

void init_array(int *a, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        a[i] = 0;
        i++;
    }
}

void counting_sort(int *a, int length)
{
    int size = find_max(a,length);
    int aux[size + 1];
    int i;
    int nb;
    int sort_arr[length];
    int idx;

    i = 0;
    init_array(aux,size);
    while (i < length)
    {   
        nb = a[i];
        aux[nb]++;
        i++;
    }
    count_aux(aux,size);
    i = 0;
    while (i < length)
    {
        nb = a[i];
        idx = aux[nb];
        sort_arr[idx - 1] = a[i];
        aux[nb]--;
        i++;
    }
    cpy_arr(sort_arr,a,length);
}