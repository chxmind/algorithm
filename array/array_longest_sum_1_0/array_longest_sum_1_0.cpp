//  给你一个只由0和1组成的字符串，找一个最长的子串，要求这个子串里面0和1的数目相等。
//  时间复杂度可以到O(n) 

#include <map>

void array_longest_sum_1_0(int* arr, int len, int* left, int* right)
{
    int cnt[2] = {0, 0};
    int* tmp = new int[len];
    std::map<int, int> m;
    *left = *right = 0;

    for (int i = 0; i < len; i++)
    {
        cnt[arr[i]]++;
        tmp[i] = cnt[0] - cnt[1];
        if (tmp[i] == 0)
        {
            *left = 0;
            *right = i;
            continue;
        }
        else
        {
            auto it = m.find(tmp[i]);
            if (it ==m.end())
            {
                m.insert({tmp[i], i});
            }
            else
            {
                if (i - it->second > *right - *left)
                {
                    *left = it->second;
                    *right = i;
                }
            }
        }
    }

    delete[] tmp;
}
