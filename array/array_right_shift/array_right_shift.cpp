/**
 * 数组循环移位
 * 将一个含有n个元素的数组向右循环移动k位，要求时间复杂度是O(n)，
 * 且只能使用两个额外的变量，这是在微软的编程之美上看到的一道题
 * 
 */

#include <string>

/**
 *  解法1，不做任何限制
 * time O(n^2), space O(1)
 */
void array_right_shift(int* arr, int len, int k)
{
	if (arr == nullptr) return;
	if (len <= 0) return;
    if (k < 0) k += len;
	k %= len;
	while (k--)
	{
		int t = arr[len - 1];
		for (int i = len - 1; i > 0; i--) arr[i] = arr[i - 1];
		arr[0] = t;
	}
}


/**
 *  解法2， 用另外一块空间搬运
 * time O(n), space O(n)
 */
void array_right_shift2(int* arr, int len, int k)
{
	if (arr == nullptr) return;
	if (len <= 0) return;
    if (k < 0) k += len;
	k %= len;

    int* tmp = new int[len];
    memcpy(tmp, arr, len);

	while (k--)
	{
		int t = arr[len - 1];
		for (int i = len - 1; i > 0; i--) arr[i] = arr[i - 1];
		arr[0] = t;
	}
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 解法3，逆序3次
 * time O(n), space O(1)
 */
void array_right_shift3(int* arr, int len, int k)
{
	if (k < 0) k += len;
	const int mid = len - (k % len);
	for (int left = 0, right = mid - 1; left < right; left++, right--) swap(&arr[left], &arr[right]);
	for (int left = mid, right = len - 1; left < right; left++, right--) swap(&arr[left], &arr[right]);
	for (int left = 0, right = len - 1; left < right; left++, right--) swap(&arr[left], &arr[right]);
}