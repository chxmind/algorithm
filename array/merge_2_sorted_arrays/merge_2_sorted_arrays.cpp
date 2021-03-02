void merge_2_sorted_arrays(int* arr1, int len1, int* arr2, int len2)
{
	if (arr1 == nullptr) return;
	if (arr2 == nullptr) return;

	int i = len1 - 1;
	int j = len2 - 1;
	int k = len1 + len2 - 1;

	while (i >= 0 && j >= 0)
		arr1[i] < arr2[j] ? 
		arr1[k--] = arr2[j--] : 
		arr1[k--] = arr1[i--];
	while (i >= 0) arr1[k--] = arr1[i--];
	while (j >= 0) arr1[k--] = arr2[j--];
}