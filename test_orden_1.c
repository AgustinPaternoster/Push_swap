#include<stdio.h>

//////////////////////////////

void order_al(int *a, int s)
{
    int i,j,swap;
    i = 0;
    int size = s;
    while(i < size)
    {
        j = 0;
        while (j < size -1 - i)
        {
            if(a[j] > a[j+1])
            {
                swap = a[j];
                a[j] = a[j+1];
                a[j+1] = swap;
            }    
            j++;
        }
        i++;
    }
}

void swap(int * a, int x , int y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void order_al2(int *a, int s)
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

void order_al3(int *a, int s)
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
int main(void)
{
    int a[10]={23,2,4,55,65,7,5,11,10,34}; 
   
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("----------------------\n");
	order_al3(a,10);
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return (0);
}
