/**
 * 最小k个数
 */

#include <vector>
#include <set>

using namespace std;

/**
 * 解法1
 * 快排思想
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