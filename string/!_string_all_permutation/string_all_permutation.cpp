#include <iostream>
using namespace std;

void string_all_permutation(char* str, char* begin)
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
		string_all_permutation(str, begin + 1);
		t = *ch;
		*ch = *begin;
		*begin = t;
	}
}

int main()
{
	char str[] = "abcd";
	string_all_permutation(str, str);

	return 0;
}