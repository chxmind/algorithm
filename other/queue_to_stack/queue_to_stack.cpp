#include <iostream>
#include <queue>
using namespace std;

class mystack {
public:
	void push(int v) 
	{
		qf->push(v);
	}

	void swap_qf_qe() 
	{
		auto t = qf;
		qf = qe;
		qe = t;
	}

	void pop()
	{
		if (qf->empty()) throw std::exception("error");
		while (qf->size() > 1)
		{
			int v = qf->front();
			qf->pop();
			qe->push(v);
		}
		qf->pop();
		swap_qf_qe();
	}

	bool empty()
	{
		return qf->empty();
	}

	int top()
	{
		if (qf->empty()) throw std::exception("error");
		int v;
		while (!qf->empty())
		{
			v = qf->front();
			qf->pop();
			qe->push(v);
		}
		swap_qf_qe();
		return v;
	}

private:
	std::queue<int> q1;
	std::queue<int> q2;
	std::queue<int>* qf = &q1;
	std::queue<int>* qe = &q2;
};

void queue_to_stack() 
{
	mystack s;
	for (size_t i = 0; i < 10; i++)
	{
		s.push(i);
	}

	for (size_t i = 0; i < 4; i++)
	{
		s.pop();
	}
	for (size_t i = 0; i < 10; i++)
	{
		s.push(i+10);
	}
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}