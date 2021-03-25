#include <iostream>
using namespace std;

class list_node
{
public:
    list_node(int v)
        : next(nullptr)
        , data(v)
    {}
public:
    list_node* next;
    int data;
};

list_node* find_middle(list_node* head)
{
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;
    
    list_node* one;
    list_node* two;

    one = two = head;
    while (two->next != nullptr)
    {
        if (two->next->next == nullptr) break;
        two = two->next->next;
        one = one->next;
    }
    return one;
}

int main()
{
    list_node node1(1);
    list_node node2(2);
    list_node node3(3);
    list_node node4(4);
    list_node node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = nullptr;

    node3.next = nullptr;


    list_node* mid = find_middle(&node1);
    cout << mid->data << endl;

	return 0;
}