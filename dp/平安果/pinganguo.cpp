/**
 * 给定一个M行N列的矩阵(M*N个格子),每个格子中放着一定数量的平安果。
 * 你从左上角的各自开始,只能向下或者向右走,目的地是右下角的格子。
 * 每走过一个格子,就把格子上的平安果都收集起来。求你最多能收集到多少平安果。
 * 注意:当经过一个格子时,需要一次性把格子里的平安果都拿走。
 */

#include <vector>
#include <iostream>
using namespace std;

void ping_an_guo(vector<vector<int>> vec, int row, int col, int& current, int& max)
{
	current += vec[row][col];
	if (col + 1 < vec[0].size()) 
		ping_an_guo(vec, row, col + 1, current, max);
	if (row + 1 < vec.size()) 
		ping_an_guo(vec, row + 1, col, current, max);

	if (row == vec.size() - 1 &&
		col == vec[0].size() - 1)
	{
		if (current > max) max = current;
	}

	current -= vec[row][col];
}

int main()
{
	vector<vector<int>> vec = 
	{ 
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};

	int result = 0;
	int current = 0;
	ping_an_guo(vec, 0 , 0, current, result);

	cout << result << endl;
	return 0;
}
