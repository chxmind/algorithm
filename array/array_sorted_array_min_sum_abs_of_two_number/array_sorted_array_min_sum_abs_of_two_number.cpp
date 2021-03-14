/**
 * 输入一串有序整数数组（正负数），求数组里两数之和绝对值最小值。（输出最小值）
 */

#include <iostream>
#include <vector>
using namespace std;

bool array_sorted_array_min_sum_abs_of_two_number(const vector<int>& vec, int& result)
{
	if (vec.size() < 2) return false;

	if (vec.front() <= 0 && vec.back() <= 0)
	{
		result = abs(vec[vec.size() - 1] + vec[vec.size() - 2]);
		return true;
	}
	else if (vec.front() <= 0 && vec.back() > 0)
	{
		int left = 0;
		int right = vec.size() - 1;
		int result_new;
		int abs_result;
		result = vec[left++] + vec[right--];
		while (left + 1 < right)
		{
			if (result == 0)
			{
				result = 0;
				return true;
			}
			else if (result < 0)
			{
				left++;
				abs_result = abs(result);
				result_new = vec[left] + vec[right];
				if (abs_result < abs(result_new))
				{
					result = abs_result;
					return true;
				}
				else
				{
					result = result_new;
				}
			}
			else
			{
				right--;
				abs_result = abs(result);
				result_new = vec[left] + vec[right];
				if (abs_result < abs(result_new))
				{
					result = abs_result;
					return true;
				}
				else
				{
					result = result_new;
				}
			}
		}
	}
	else
	{
		result = abs(vec[0] + vec[1]);
		return true;
	}
}

int main()
{
	int result = 0;
	vector<int> vec = { -5,-2,3,4,10 };
	array_sorted_array_min_sum_abs_of_two_number(vec, result);

	cout << result << endl;
	return 0;
}
