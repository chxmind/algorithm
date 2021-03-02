// 给定一个含有n个元素的整型数组a，其中只有一个元素出现奇数次，找出这个元素

int array_find_appear_odd_cnt_element(int* arr, int len)
{
    int t = 0;
    for (int i = 0; i < len; i++) t ^= arr[i];
    return t;
}