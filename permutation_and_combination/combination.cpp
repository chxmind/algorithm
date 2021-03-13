#include <vector>
#include <iostream>
using namespace std;

void combination(const vector<int>& arr,int start, int k, vector<int>& result)
{
	if (k > arr.size()) return;
	if (start < 0) return;

	if (result.size() == k)
	{
		for (auto it = result.begin(); it != result.end(); it++)
			cout << *it << "\t";
		cout << endl;
		return;
	}
	const int left = arr.size() -(k - result.size());
	for (int i = start; i <= left; i++)
	{
        // for repeated value
		bool flag = false;
		for (int j = start; j < i; j++)
		{
			if (arr[i] == arr[j]) 
			{
				flag = true;
				break;
			}
		}
		if (flag) continue;
		result.push_back(arr[i]);
		combination(arr, i + 1, k, result);
		result.pop_back();
	}
}

int main()
{
	vector<int> arr = {1,2,3,4};
	vector<int> result;
	combination(arr, 0, 3, result);

	return 0;
}