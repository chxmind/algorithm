/**
 * leetcode 300
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
 * 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 * 
    示例 1：
    输入：nums = [10,9,2,5,3,7,101,18]
    输出：4
    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
    示例 2：

    输入：nums = [0,1,0,3,2,3]
    输出：4
    示例 3：

    输入：nums = [7,7,7,7,7,7,7]
    输出：1
 */

#include <iostream>
#include <vector>
using namespace std;

void max_sub(const vector<int>& vec, int index, vector<int>& seq, int& result)
{
    if (seq.size() > result) result = seq.size();
    if (index >= vec.size()) return;

    if (seq.empty())
    {
        seq.push_back(vec[index]);
        max_sub(vec, index + 1, seq, result);
        seq.pop_back();
    }
    else
    {
        for (int i = index; i < vec.size(); i++)
        {
            if (vec[i] <= seq.back()) continue;
            seq.push_back(vec[i]);
            max_sub(vec, i + 1, seq, result);
            seq.pop_back();
        }
    }
}

int max_subsequence(const vector<int>& vec)
{
    vector<int> seq;
    int result = 0;
    for (int i = 0; i < vec.size(); i++)
        max_sub(vec, i, seq, result);
    return result;
}


int main()
{
	int result = 0;
    //vector<int> vec = { 10,9,2,5,3,7,101,18 };
    //vector<int> vec = { 7,7,7,7,7,7,7,7,7 };
    vector<int> vec = { 0, 1, 0, 3, 2, 3 };
    result=max_subsequence(vec);
	cout << result << endl;

	return 0;
}
