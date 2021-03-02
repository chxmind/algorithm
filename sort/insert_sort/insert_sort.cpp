void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void insert_sort(int* arr, int len)
{
	if (arr == nullptr) return;
	if (len <= 0) return;

	int t, i, j;
	for (i = 1; i < len; i++)
	{
		t = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > t)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = t;
	}
}

void insert_sort2(int* arr, int len)
{
	for (int i = 1; i < len; i++)
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
			swap(&arr[j], &arr[j + 1]);
}
