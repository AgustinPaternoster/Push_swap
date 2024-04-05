#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printtest(int argc, char **argv)
{
    int i = 0;

    while (i < argc)
    {
        printf("%s\n",argv[i]);
        i++;
    }
} 

int main(int argc, char **argv) 
{
    printtest(argc - 1 , argv + 1);
    return (0);
}