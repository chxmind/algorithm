void move_zero(int* arr, const int size)
{
	if (arr == nullptr) return;
	if (size == 0) return;

	int index = 0;
	int cnt = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0) cnt++;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0) continue;
		arr[index++] = arr[i];
	}

	for (size_t i = size - cnt; i < size; i++)
	{
		arr[i] = 0;
	}
}

void move_zero2(int* arr, int size)
{
	if (arr == nullptr) return;
	if (size == 0) return;

	int signal = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0) continue;
		arr[signal] = arr[i];
		if (i != signal) arr[i] = 0;
		signal++;
	}
}