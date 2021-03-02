
void count_sort(int* arr, int len)
{
	if (arr == nullptr) return;
	if (len <= 0) return;
	int max, min;
	min = max = arr[0];

	for (size_t i = 1; i < len; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	int size = max - min + 1;
	int* arrcnt = new int[size];
    for (size_t i = 0; i < size; i++) arrcnt[i] = 0;
	for (size_t i = 0; i < len; i++) arrcnt[arr[i] - min]++;
	for (size_t i = 0, j = 0; j < size; j++)
		while (arrcnt[j]-- > 0) arr[i++] = j;

	delete arrcnt;
}