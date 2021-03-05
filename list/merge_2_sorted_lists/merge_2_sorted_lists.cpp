class list_node
{
public:
	int data;
	list_node* next;
};

list_node* merge_2_sorted_lists(list_node* node1, list_node* node2)
{
	if (node1 == nullptr && node2 == nullptr) return nullptr;
	if (node1 == nullptr) return node2;
	if (node2 == nullptr) return node1;

	list_node* head;
	list_node* cur;
	if (node1->data <= node2->data)
	{
		head = cur = node1;
		node1 = node1->next;
	}
	else
	{
		head = cur = node2;
		node2 = node2->next;
	}

	while (node1 != nullptr && node2 != nullptr)
	{
		if (node1->data <= node2->data)
		{
			cur->next = node1;
			node1 = node1->next;
		}
		else
		{
			cur->next = node2;
			node2 = node2->next;
		}
		cur = cur->next;
	}

	if (node1 == nullptr) cur->next = node2;
	else if (node2 == nullptr) cur->next = node1;

	return head;
}
