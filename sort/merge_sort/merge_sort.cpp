void merge_sort(int* arr, int left, int right, int* temp)
{
	if (left >= right) return;

	int mid = (left + right) >> 1;
	merge_sort(arr, left, mid, temp);
	merge_sort(arr, mid+1, right, temp);

	int i = left;
	int j = mid + 1;
	int m = mid;
	int n = right;
	int k = left;
	while (i <= m && j <= n)
		arr[i] <= arr[j] ? temp[k++] = arr[i++]: temp[k++] = arr[j++];
	while (i <= m) temp[k++] = arr[i++];
	while (j <= n) temp[k++] = arr[j++];
	for (int i = left; i <= right; i++) arr[i] = temp[i];
}

void merge_sort(int* arr, int len)
{
	if (arr == nullptr) return;
	if (len <= 0) return;
	int* temp = new int[len];
	merge_sort(arr, 0, len - 1, temp);
	delete[] temp;
}