


/**********************************************************************
 * 剑指 p39
 **********************************************************************/

#include <set>
#include <algorithm>

// use set
// time O(n), space O(n)
bool array_has_repeated_number(int* arr, int len)
{
    std::set<int> s;
    for (int i = 0; i < len; i++)
    {
        auto it = s.find(arr[i]);
        if (it == s.end()) s.insert(arr[i]);
        else return true;
    }
    return false;
}

// sort and find
// time O(nlogn), space O(1)
bool array_has_repeated_number2(int* arr, int len)
{
    std::set<int> s;
    std::sort(arr, arr+len, std::less<int>());
    for (int i = 1; i < len; i++)
        if (arr[i] == arr[i-1]) return true;
    return false;
}


// compare and swap
// time O(n), space O(1)
// 每个数字最多交换2次就能找到属于自己的位置
// 因此时间复杂度为O(n)
bool array_has_repeated_number4(int* arr, int len, int* duplication)
{
	if (arr == nullptr) return false;
	if (duplication == nullptr) return false;
	if (len <= 0) return false;
	for (int i = 0; i < len; i++)
		if (arr[i] < 0 || arr[i] >= len) return false;

	for (int i = 0; i < len; i++)
	{
		if (i == arr[i]) continue;
		int t = arr[i];
		if (arr[t] == t)
		{
			*duplication = t;
			return true;
		}
		arr[i] = arr[t];
		arr[t] = t;
		i--;
	}
	return false;
}

// compare and swap
// time O(n), space O(1)
// 另一种写法
bool array_has_repeated_number42(int* arr, int len, int* duplication)
{
	if (arr == nullptr) return false;
	if (duplication == nullptr) return false;
	if (len <= 0) return false;
	for (int i = 0; i < len; i++)
		if (arr[i] < 0 || arr[i] >= len) return false;

	for (int i = 0; i < len; i++)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*duplication = arr[i];
				return true;
			}
			int t = arr[i];
			arr[i] = arr[t];
			arr[t] = t;
		}
	}
	return false;
}



/**********************************************************************
 * 剑指 p41
 **********************************************************************/


// use hashtable
// time O(n), space O(n)
bool array_has_repeated_number_no_modify(int* arr, int len, int* duplication)
 {
    if (arr == nullptr) return false;
	if (duplication == nullptr) return false;
	if (len <= 0) return false;
	for (int i = 0; i < len; i++)
	if (arr[i] < 0 || arr[i] >= len) return false;

     bool result = false;
     int* tmp = new int[len];
     memset(tmp, 0, sizeof(int)*len);

     for (int i = 0; i < len; i++)
     {
         int t = arr[i];
         if (tmp[t] >0) 
         {
             *duplication = t;
             result = true;
             break;
         }
         tmp[t]++;
     }
     delete[] tmp;
     return result;
 }

