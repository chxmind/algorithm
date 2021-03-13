#include <iostream>
#include <stack>
using namespace std;

void permutation_string(char* str, char* begin)
{
	if (str == nullptr) return;
	if (begin == nullptr) return;
	if (*begin == '\0')
	{
		cout << str << endl;
		return;
	}

	for (char* ch = begin; *ch != '\0'; ch++)
	{
		char t;
		t = *ch;
		*ch = *begin;
		*begin = t;
		permutation_string(str, begin + 1);
		t = *ch;
		*ch = *begin;
		*begin = t;
	}
}

void permutation_array(int* arr, int left, int right)
{
	if (arr == nullptr) return;
	if (left < 0) return;
	if (left > right) return;

	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	for (int i = left; i <= right; i++)
	{
		int t = 0;
		// for repeated value
		for (int j = left; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				t = 1;
				break;
			}
		}
		if (t) continue;

		t = arr[left];
		arr[left] = arr[i];
		arr[i] = t;
		permutation_array(arr, left + 1, right);
		t = arr[left];
		arr[left] = arr[i];
		arr[i] = t;
	}
}

int main()
{
	char str[] = "abcd";
	permutation_string(str, str);

    int arr[] = {1,2,3,4};
	permutation_array(arr, 0, 3);

	return 0;
}
