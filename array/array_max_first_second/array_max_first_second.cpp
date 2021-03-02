
void adjust_heap(int* arr, int len)
{
	int parent = (len >> 1) - 1;
	
	while (parent >= 0)
	{
		int child = (parent << 1) + 1;
		if (child + 1 < len && arr[child] < arr[child + 1]) child++;
		if (arr[child] > arr[parent]) {
			int t = arr[child];
			arr[child] = arr[parent];
			arr[parent] = t;
		}
		parent--;
	}
	int t = arr[0];
	arr[0] = arr[len-1];
	arr[len - 1] = t;
}

void array_max_first_second(int* arr, int len, int* first, int* second)
{
	adjust_heap(arr, len);
	adjust_heap(arr, len - 1);
	*first = arr[len - 1];
	*second = arr[len - 2];
}