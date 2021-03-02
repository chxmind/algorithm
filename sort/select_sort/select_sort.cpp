void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int max_index(int* arr, int left, int right)
{
	if (arr == nullptr) return -1;
	if (left >= right) return -1;
	int max = arr[left];
	int index = left;
	for (size_t i = left+1; i < right; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

void select_sort(int* arr, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		int t = max_index(arr, i, len);
		if (t == -1) return;
		swap(&arr[i], &arr[t]);
	}
}