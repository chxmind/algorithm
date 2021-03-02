// 给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数

int array_find_only_repeated_element(int* arr, int len)
{
    int sum_std = ((1 + 1000) * 1000) >> 1;
    int sum = 0;
    for (int i = 0; i < len; i++) sum+=arr[i];
    return sum - sum_std;
}