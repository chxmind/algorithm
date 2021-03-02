void quick_sort(int* arr, int l, int r)
{
	if (l >= r) return;

	int i = l, j = r, x = arr[l];
	while (i < j)
	{
		while (i < j && arr[j] >= x) j--;
		if (i < j) arr[i++] = arr[j];
		while (i < j && arr[i] < x) i++;
		if (i < j) arr[j--] = arr[i];
	}
	arr[i] = x;
	quick_sort(arr, l, i-1);
	quick_sort(arr, i+1, r);
}