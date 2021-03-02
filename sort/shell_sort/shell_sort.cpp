void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void shell_sort(int* arr, int len)
{
	int i, j, gap;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++)
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
				swap(&arr[j], &arr[j + gap]);
}
