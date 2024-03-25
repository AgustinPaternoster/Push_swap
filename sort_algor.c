#include "push_swap.h"

void swap(int * a, int x , int y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void cpy_array(int *src, int *dst,int ini ,int end)
{
	int i;

	i = 0;
	while(i + ini < end)
	{
		src[i+ini] = dst[i];
		i++;
	}
}
void merge_sort(int * a, int size)
{
   	int middle;
	int *left_sort;
	int *right_sort;

	if  (size == 1)
	   return;
	middle = size / 2;
	left_sort = malloc(sizeof(int)*middle);
	right_sort = malloc(sizeof(int)*size - middle);
	cpy_array(a,left_sort,0,middle);
	cpy_array(a,right_sort,size - middle , size);

}

void insertion_sort(int * a, int size)
{
   int i;
   int j;
   int tmp;

   i = 1;
   while (i < size )
   {
    j = i - 1;
    tmp = a[i];
    while( j >= 0 && a[j] > tmp )
    {
        a[j+1] = a[j];
        a[j] = tmp;
        j--;
    }
    i++;
   }
}

void selection_sort(int *a, int s)
{
    int i;
    int j;
    int minidx;
    
	i = 0;
    while (i < s -1)
    {
        j = i;
		minidx = i;
		while ( j < s - 1 )
		{
			if (a[minidx] > a[j+1])
				swap(a,minidx,j+1);
			j++;
		}
		i++;	
    }
    
}

void buble_sort(int *a, int s)
{
    int i,j;
    i = 0;
    int size = s;
    while(i < size)
    {
        j = 0;
        while (j < size -1 - i)
        {
            if(a[j] > a[j+1])
            {
                swap(a,j,j+1);
            }    
            j++;
        }
        i++;
    }
}

void simple_sort(int *a, int s)
{
	int i;
	int tmp;

	i = 0;
	while (i < s - 1)
	{
		if (a[i] > a[i+1] )
		{
			swap(a,i,i+1);
			i = 0;
			continue;	
		}
		i++;
	}
}
