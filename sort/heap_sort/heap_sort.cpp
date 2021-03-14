#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// void adjust_heap(int* arr, int len)
// {
// 	if (arr == nullptr) return;
// 	int parent = (len >> 1) - 1;

// 	while (parent >= 0)
// 	{
// 		int child = (parent << 1) + 1;
// 		if (child + 1 < len && arr[child] < arr[child + 1]) child += 1;
// 		if (arr[child] > arr[parent]) swap(&arr[child], &arr[parent]);
// 		parent--;
// 	}
// }

// void heap_sort(int* arr, int len)
// {
// 	int cur_len = len;
// 	while (cur_len > 0)
// 	{
// 		adjust_heap(arr, cur_len);
// 		swap(arr[0], arr[--cur_len]);
// 	}
// }

void max_heapify(int* arr, int left, int right)
{
	int parent = left;
	int child = (left << 1) + 1;

	while (child <= right)
	{
		if (child + 1 <= right && arr[child] < arr[child + 1]) child++;
		if (arr[child] <= arr[parent]) break;
		swap(arr[child], arr[parent]);
		parent = child;
		child = (parent << 1) + 1;
	}
}

void heap_sort(int* arr, int len)
{
	for (int i = (len >> 1) - 1; i >= 0; i--)
		max_heapify(arr, i, len-1);

	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

int main()
{
	int arr[] = { 1,5,4,4,6,7,5,4 };
	heap_sort(arr, 8);
	for (int i = 0; i < 8; i++)
		cout << arr[i] << endl;
	
	return 0;
}