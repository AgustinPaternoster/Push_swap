#include "push_swap.h"



void quick_sort(int *a,int lenght)
{
    quick_sort_recur(a, 0 , lenght - 1);
}

void quick_sort_recur(int arr[],int low, int high)
{
    if (low < high)
    {
    int pivot_index = partition(arr ,low, high);
    quick_sort_recur(arr , low , pivot_index -1);
    quick_sort_recur(arr , pivot_index  +1 , high);
    }
}

int partition(int arr[],int low, int high)
{
    int pivot_value = arr[high];
    int i = low;
    int j = low;
    while (j < high)
    {
        if (arr[j] <= pivot_value)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
        j++;
    }

    swap(&arr[i],&arr[high]);
    return i;
    
}

void swap(int *x , int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}