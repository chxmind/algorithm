#include <stack>
#include <iostream>
using namespace std;


template<typename T>
class my_stack
{
public:
	void push(const T& value)
	{
		_s.push(value);
		if (_s_min.empty() || _s_min.top() > value)
			_s_min.push(value);
		else
			_s_min.push(_s_min.top());
	}
	void pop()
	{
		if (_s.empty()) return;
		_s.pop();
		_s_min.pop();
	}

	T& top()
	{
		assert(!_s.empty());
		return _s.top();
	}

	bool empty()
	{
		return _s.empty();
	}

	T& min()
	{
		assert(!_s.empty());
		return _s_min.top();
	}
private:
	stack<T> _s;
	stack<T> _s_min;
};

int main()
{
	my_stack<int> s;
	for (int i = 10; i > 5; i--)
		s.push(i);

	for (int i = 5; i < 10; i++)
		s.push(i);

	while (!s.empty())
	{
		cout << s.top() << "\t" << s.min() << endl;
		s.pop();
	}
	return 0;
}