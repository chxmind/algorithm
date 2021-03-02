class list_node
{
public:
	int data;
	list_node* next;
};

list_node* list_nth_from_last(list_node* head, int k)
{
	if (head == nullptr) return nullptr;

	list_node* a;
	list_node* b;
	a = b = head;
	k--;
	while (k-- && a != nullptr) a = a->next;
	if (a == nullptr) return nullptr;

	while (a->next != nullptr)
	{
		a = a->next;
		b = b->next;
	}

	return b;
}