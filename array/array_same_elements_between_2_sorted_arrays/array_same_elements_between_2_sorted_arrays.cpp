
void array_same_elements_between_2_sorted_arrays(int* arr1, int len1, int* arr2, int len2, int* out, int* out_len)
{
	int k = 0;
	*out_len = 0;

	for (int i = 0, j = 0; 
		i < len1 && j < len2;)
	{
		if (arr1[i] < arr2[j]) i++;
		else if (arr1[i] > arr2[j]) j++;
		else
		{
			if (k == 0 || (out[k - 1] != arr1[i])) out[k++] = arr1[i];
			i++;
			j++;
		}
	}
	*out_len = k;
}



int binary_search(int* arr, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (arr[mid] < target) left = mid +1;
		else if (arr[mid] > target) right = mid;
		else return mid;
	}
	return -1;
}

void array_same_elements_between_2_sorted_arrays2(int *arr1, int len1, int* arr2, int len2, int* out, int* out_len)
{
	int* arr_short = arr1;
	int* arr_long = arr2;

	int len_short = len1;
	int len_long = len2;

	if (len2 < len1) 
	{
		arr_short = arr2;
		arr_long = arr1;
		len_short = len2;
		len_long = len1;
	}

	int left = 0;
	int right = len_long-1;
	int k = 0;
	for (int i = 0; i < len_short; i++)
	{
		int index = binary_search(arr_long, left, right, arr_short[i]);
		if (index == -1) continue;
		left = index;
		if (k==0 || out[k-1] != arr_short[i])
			out[k++] = arr_short[i];
	}
	*out_len = k;
}