/**
 *  找到数组中出现次数超过数组长度一半的元素
 */

#include <algorithm>
#include <vector>

using namespace std;

//  check if really over half
bool check_cnt(const vector<int>& vec, const int value)
{
    int times = 0;
    for (auto it = vec.begin(); it != vec.end(); it++)
        if (*it == value) times++;
    
    return times * 2 > vec.size();
}

/**
 * 解法1
 * 先排序，后取中间的数
 */
bool array_element_cnt_over_half(const vector<int>& vec, int& result)
{
    if (vec.size() == 0) return false;
    std::sort(vec.begin(), vec.end());
    result = vec[vec.size()/2];
    return check_cnt(vec, result);
}

/**
 * 解法2
 * 快排思想
 * 取中间的数
 */

int partition(vector<int>& vec, int left, int right)
{
    int mid = (left+right) >> 1;
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

bool array_element_cnt_over_half_2(vector<int>& vec, int& result)
{
    if (vec.size() == 0) return false;
	int left = 0;
	int right = vec.size() - 1;
	int mid = vec.size() / 2;
	int index = partition(vec, left, right);
	while (index != mid)
	{
		if (index < mid)
		{
			left = index + 1;
			index = partition(vec, left, right);
		}
		else
		{
			right = index - 1;
			index = partition(vec, left, right);
		}
	}

	result = vec[mid];
	return  check_cnt(vec, result);
}


/**
 * 解法3
 * 用空间复杂度O(1)统计个数
 * 遇到相同的数+1
 * 遇到不同的数-1
 */
bool array_element_cnt_over_half_3(vector<int>& vec, int& result)
{
	if (vec.size() == 0) return false;

	result = vec[0];
	int times = 1;

	for (int i = 1; i < vec.size(); i++)
	{
		if (result == vec[i]) times++;
		else if (times == 1) result = vec[i];
		else times--;
	}

	return check_cnt(vec, result);
}