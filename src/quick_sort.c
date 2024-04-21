#include "../include/push_swap.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot_value)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort_recur(int arr[], int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort_recur(arr, low, pivot_index -1);
		quick_sort_recur(arr, pivot_index + 1, high);
	}
}

void	quick_sort(int *a, int lenght)
{
	quick_sort_recur(a, 0, lenght - 1);
}
