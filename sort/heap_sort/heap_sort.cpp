void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void adjust_heap(int* arr, int len)
{
	if (arr == nullptr) return;
	int parent = len / 2 - 1;

	while (parent >= 0)
	{
		int child = (parent << 1) + 1;
		if (child + 1 < len && arr[child] < arr[child + 1]) child += 1;
		if (arr[child] > arr[parent]) swap(&arr[child], &arr[parent]);
		parent--;
	}
}

void heap_sort(int* arr, int len)
{
	int cur_len = len;
	while (cur_len > 0)
	{
		adjust_heap(arr, cur_len);
		swap(&arr[0], &arr[--cur_len]);
	}
}