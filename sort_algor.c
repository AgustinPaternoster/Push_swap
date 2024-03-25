

void swap(int * a, int x , int y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void merge_sort(int * a, int)
{
    
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