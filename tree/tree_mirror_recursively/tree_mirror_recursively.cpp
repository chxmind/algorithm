
#include <iostream>

using namespace std;

class tree_node
{
public:
	tree_node()
		: left(nullptr)
		, right(nullptr)
		, data(0)
	{
	}
	tree_node(int value)
		: left(nullptr)
		, right(nullptr)
		, data(value)
	{
	}

public:
	tree_node* left;
	tree_node* right;
	int data;
};

void tree_mirror_recursively(tree_node* root)
{
	if (root == nullptr) return;
	tree_node* t = root->left;
	root->left = root->right;
	root->right = t;
	tree_mirror_recursively(root->left);
	tree_mirror_recursively(root->right);
}

void print_tree(tree_node* root)
{
	if (root == nullptr) return;
	cout << root->data << endl;
	print_tree(root->left);
	print_tree(root->right);
}

int main()
{
	tree_node* root1;

	root1 = new tree_node(1);
	root1->left = new tree_node(2);
	root1->right = new tree_node(3);
	root1->left->left = new tree_node(4);
	root1->left->right = new tree_node(5);
	root1->right->left = new tree_node(6);
	root1->right->right = new tree_node(7);
	root1->left->left->left = new tree_node(8);
	root1->left->left->right = new tree_node(9);

	tree_node* root2;
	root2 = new tree_node(4);
	root2->left = new tree_node(8);
	root2->right = new tree_node(9);

	cout << "-----------" << endl;
	print_tree(root1);
	cout << "-----------" << endl;
	tree_mirror_recursively(root1);
	cout << "-----------" << endl;
	print_tree(root1);
	cout << "-----------" << endl;

	return 0;
}