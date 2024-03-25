#include "push_swap.h"

int main(void)
{
    int a[9]={23,2,4,55,65,7,5,11,10}; 
   
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("----------------------\n");
	merge_sort(a,9);
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return (0);
}
