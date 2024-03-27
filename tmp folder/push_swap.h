#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void buble_sort(int *a, int s);
void simple_sort(int *a, int s);
void selection_sort(int *a, int s);
void insertion_sort(int * a, int size);
void merge_sort(int * a, int size);
void swap(int *x , int *y);
void quick_sort_recur(int arr[],int low, int high);
int partition(int arr[],int low, int high);
void quick_sort(int *a,int lenght);
#endif
