void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int* arr, int len)
{
	for (size_t i = 0; i < len - 1; i++)
		for (size_t j = 0; j < len - 1 - i; j++)
			if (arr[j] < arr[j + 1]) 
				swap(&arr[j], &arr[j+1]);
}
