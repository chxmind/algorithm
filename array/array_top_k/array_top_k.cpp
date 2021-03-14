/**
 * 最小k个数
 */

#include <vector>
#include <set>

using namespace std;

/**
 * 解法1
 * 快排思想
 * 时间 平均 O(n)
 * 空间 O(1)
 */
int partition(vector<int>& vec, int left, int right)
{
    int mid = (left + right) >> 1;
    int t = vec[left];
    while (left < right)
    {
        while (left < right && vec[right] >= t) right--;
        if (left < right) vec[left++] = vec[right];
        while (left < right && vec[left] <= t) left++; 
        if (left < right) vec[right--] = vec[left];
        vec[left] = t;
    }
    return left;
}

bool array_top_k(vector<int>& vec, int k, int& result)
{
    if (vec.size() == 0) return false;
    int left = 0;
    int right = vec.size() -1;
    int index = partition(vec, left, right);
    while (index != k)
    {
        if (index > k) 
        {
            right = index-1;
            index = partition(vec, left, right);
        }
        else
        {
            left = index + 1;
            index = partition(vec, left, right);
        }
    }

    result = vec[result];

    return true;
}

/**
 * 解法2
 * 堆排序
 * 时间 O(nlogk)
 * 空间 O(k)
 */
bool array_top_k_2(const vector<int>& vec, int k, int& result)
{
	multiset<int, greater<int>> s;
	if (k < 1) return false;
	if (vec.size() < k) return false;

	for (auto& it : vec)
	{
		if (s.size() < k)
		{
			s.insert(it);
		}
		else
		{
			if (it < *s.begin())
			{
				s.erase(s.begin());
				s.insert(it);
			}
		}
	}

	result = *s.begin();
	return true;
}


/**
 * 解法3
 * 自己实现的堆，待优化
 * 添加插入删除方法
 */
void adjust_heap(int* arr, const int len)
{
	int parent = (len >> 1) - 1;
	while (parent >= 0)
	{
		int child = (parent << 1) + 1;
		if (child + 1 < len && arr[child] < arr[child + 1]) child++;
		if (arr[child] > arr[parent]) swap(arr[child], arr[parent]);
		parent--;
	}
}

bool array_top_k_3(const vector<int>& vec, const int k, int& result)
{
	if (k <= 0) return false;
	if (vec.size() < k) return false;
	int* arr = new int[k];
	int arr_size = 0;
	for (auto& it : vec)
	{
		if (arr_size < k)
		{
			arr[arr_size] = it;
			adjust_heap(arr, ++arr_size);
		}
		else
		{
			if (it < arr[0])
			{
				arr[0] = it;
				adjust_heap(arr, k);
			}
		}
	}

	result = arr[0];
	delete[] arr;
	return true;
}
