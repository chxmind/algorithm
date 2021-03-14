#include <iostream>
#include <stack>
using namespace std;

class myqueue {
public: 
	void push(int v) 
	{
		s1.push(v);
	}
	void pop() 
	{
		int v = front();
		s2.pop();
	}
	bool empty() {
		return s1.empty() && s2.empty();
	}
	int front() 
	{
		if (!s2.empty()) {
			int v = s2.top();
			return v;
		}
		else {
			if (s1.empty()) throw std::exception("error");
			int v;
			while (!s1.empty()) {
				v = s1.top();
				s1.pop();
				s2.push(v);
			}
			return v;
		}
	}

private:
	std::stack<int> s1, s2;
};

void stack_to_queue()
{
	myqueue q;
	for (int i = 0; i < 10; i++) 
	{
		q.push(i);
	}
	for (int i = 0; i < 3; i++) 
	{
		q.pop();
	}
	for (int i = 0; i < 10; i++) 
	{
		q.push(i+10);
	}

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

}