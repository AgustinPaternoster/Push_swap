#include "push_swap.h"

int main(void)
{
    int a[10]={23,2,4,55,65,7,5,11,10,34}; 
   
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("----------------------\n");
	insertion_sort(a,10);
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return (0);
}
