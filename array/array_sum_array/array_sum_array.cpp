long array_sum_array(int* arr, int len)
{
    if (arr == nullptr) return -1;
    if (len <= 0) return -1;
    long result = 0;
    for (int i = 0; i < len; i++)
        result += arr[i];
    return result;
}

long array_sum_array2(int* arr, int left, int right)
{
	if (arr == nullptr) return 0;
	if (left >= right) return 0;
	return array_sum_array2(arr, left+1, right) + arr[left];
}
