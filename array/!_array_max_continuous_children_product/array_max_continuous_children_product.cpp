/**
 * 给定一个整型数组a，求出最大连续子段的乘积，比如 1， 2， -8， 12， 7则输出12 * 7 = 84
 */

#include <algorithm>

long array_max_continuous_children_product(int* arr, int len)
{
    if (arr == nullptr) return ;
    if (len <= 0) return;
    long max_product = 1;
    long min_product = 1;
    long result = 1;

    for (int i = 0; i < len; i++)
    {
        int& v = arr[i];
        if (v > 0)
        {
            max_product *= v;
            min_product = std::min(min_product * v, 1L);
        }
        else if (v < 0)
        {
            int t = max_product;
            max_product = std::max(min_product * v, 1L);
            min_product = t * v;
        }
        else
        {
            max_product = min_product = 1;
        }  
        result = std::max(result, max_product);
    }
    return result;
}