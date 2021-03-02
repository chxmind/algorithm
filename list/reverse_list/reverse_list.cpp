class list_node
{
public:
	int data;
	list_node* next;
};

list_node* reverse_list(list_node* head)
{
	if (head == nullptr) return head;
	if (head->next == nullptr) return head;

	list_node* prev = head;
	list_node* next = head->next;

	while (next != nullptr) {
		list_node* t = next->next;
		next->next = prev;
		prev = next;
		next = t;
	}

	head->next = nullptr;
	return prev;
}