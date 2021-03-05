#include <iostream>

class list_node
{
public:
	list_node(int d)
		: data(d)
		, prev(nullptr)
		, next(nullptr)
	{}
	list_node()
		:data(0)
		, prev(nullptr)
		, next(nullptr)
	{}
	int data;
	list_node* prev;
	list_node* next;
};

void print(list_node* node)
{
	while (node != nullptr)
	{
		std::cout << node->data << std::endl;
		node = node->next;
	}
}

list_node* meet_node(list_node* node)
{
	if (node == nullptr) return nullptr;

	list_node* p1 = node;
	list_node* p2 = node;

	do
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == nullptr) return nullptr;
		p2 = p2->next;
	} while (p2 != nullptr && p1 != p2);

	return p2;
}

int cnt_loop_length(list_node* node)
{
	list_node* t = node;
	int len = 1;
	while (t->next != node)
	{
		len++;
		t = t->next;
	}
	return len;
}

list_node* entry_node_of_loop(list_node* node)
{
	list_node* the_node = meet_node(node);
	if (the_node == nullptr) return nullptr;
	int len = cnt_loop_length(the_node);

	list_node* p1 = node;
	list_node* p2 = node;

	while (len--) p2 = p2->next;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

int main(int argc, char* argv[])
{
	list_node* node;
	list_node* cur_node;

	cur_node = node = new list_node(0);
	for (int i = 1; i < 10; i++)
	{
		cur_node->next = new list_node(i);
		cur_node = cur_node->next;
	}
	list_node* last_node = cur_node;
	cur_node = node;

	while (cur_node->data != 3) cur_node = cur_node->next;
	last_node->next = cur_node;
	//       ______________
	//       |			          |
	// 0 1 2 3 4 5 6 7 8 9
	list_node* entry = entry_node_of_loop(node);

	return 0;
}