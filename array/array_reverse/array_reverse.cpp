
/**
 * 反转数组/字符串
 * time O(n), space O(1)
 */
void array_reverse(int* arr, int len)
{
    if (arr == nullptr) return;
    if (len <= 0) return;

    int left = 0;
    int right = len -1;

    for (int left = 0, right = len -1; left < right; left++, right--) 
    {
        int t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;
    }
}