#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool match_brackets(const string& str)
{
	auto is_left = [](char c) {
		if (c == '(') return true;
		if (c == '[') return true;
		if (c == '{') return true;
		return false;
	};

	auto is_right = [](char c) {
		if (c == ')') return true;
		if (c == ']') return true;
		if (c == '}') return true;
		return false;
	};

	auto is_bracket = [&](char c)
	{
		return is_left(c) || is_right(c);
	};

	stack<char> s;
	for (auto& c : str)
	{
		if (!is_bracket(c)) continue;
		if (s.empty())
		{
			if (is_right(c)) return false;
			s.push(c);
		}
		else
		{

			if (is_left(c))
			{
				s.push(c);
			}
			else
			{
				if (s.top() == '(' && c == ')' ||
					s.top() == '[' && c == ']' ||
					s.top() == '{' && c == '}')
				{
					s.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}
	return s.empty();
}

int main()
{
	auto result = match_brackets("(1+2)/(0.5+1)");
	cout << result << endl;
	return 0;
}