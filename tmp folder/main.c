#include "push_swap.h"

int main(void)
{
    int b = 9;
    int a[9] = {23,2,4,77,66,4,16,1,9}; 
   
    for(int i = 0; i < b; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("----------------------\n");
	merge_sort(a,b);
    for(int i = 0; i < b; i++)
        printf("%d ", a[i]);
    return (0);
}
