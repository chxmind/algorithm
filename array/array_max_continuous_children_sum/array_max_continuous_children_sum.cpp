// 给定一个整型数组a，求出最大连续子段之和，如果和为负数，则按0计算，比如1， 2， -5， 6， 8则输出6 + 8 = 14

int array_max_continuous_children_sum(int* arr, int len)
{
	int sum = 0;
	int cur_sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] + cur_sum > 0)
		{
			cur_sum += arr[i];
		}
		else
		{
			if (cur_sum > sum) sum = cur_sum;
			cur_sum = 0;
		}
	}
	if (cur_sum > sum) 
		sum = cur_sum;

	return sum;
}