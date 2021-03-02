#include <iostream>
#include <stack>
#include <functional>

using namespace std;

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

void print_list(ListNode *head) {
	if (head == nullptr) return;
	head = head->m_pNext;
	while (head != nullptr) {
		cout << head->m_nKey << endl;
		head = head->m_pNext;
	}
}

void print_list_reverse_stack(ListNode* head) {
	std::stack<ListNode*> s;
	if (head == nullptr) return;
	head = head->m_pNext;
	while (head != nullptr) {
		s.push(head);
		head = head->m_pNext;
	}

	while (!s.empty()) {
		head = s.top();
		s.pop();
		cout << head->m_nKey << endl;
	}
}

void print_list_reverse_recursion(ListNode* head) {
	if (head == nullptr) return;
	std::function<void(ListNode*)> print = [&](ListNode* p) {
		if (p->m_pNext != nullptr) print(p->m_pNext);
		cout << p->m_nKey << endl;
	};

	print(head->m_pNext);
}