// 数组中元素的最短距离
// 给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小

#include <algorithm>
using namespace std;

int array_min_distance(int* arr, int len)
{
	sort(arr, arr+len, std::less<int>());

	int min = arr[1] - arr[0];
	for (int i = 0; i < len - 1; i++)
	{
		int t = arr[i + 1] - arr[i];
		if (t < min) min = t;
	}

	return min;
}