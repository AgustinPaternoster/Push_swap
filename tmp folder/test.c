#include <stdlib.h>
#include <stdio.h>
#include <limits.h>



int findmax(int *arr)
{
    int i = 0;
    int max = arr[0];
    
    while (i < 4)
    {
        if (max < arr[i+1])
            max = arr[i+1];
        i++;
    }
    return max;
}

int main(int argc, char **argv) 
{   
    int i[5] = { 3, -1 , 4 , 54 , 21};
    
    printf("%d",findmax(i));
    return (0);
}