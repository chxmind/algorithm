
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

bool does_tree1_have_tree2(tree_node* root1, tree_node* root2)
{
	if (root2 == nullptr) return true;
	if (root1 == nullptr) return false;
	if (root1->data != root2->data) return false;

	return does_tree1_have_tree2(root1->left, root2->left)
		&& does_tree1_have_tree2(root1->right, root2->right);
}

bool tree_has_subtree(tree_node* root1, tree_node* root2)
{
	bool result = false;
	if (root1 != nullptr && root2 != nullptr)
	{
		if (root1->data == root2->data) result = does_tree1_have_tree2(root1, root2);
		if (!result) result = tree_has_subtree(root1->left, root2);
		if (!result) result = tree_has_subtree(root2->right, root2);
	}

	return result;
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

	bool result = tree_has_subtree(root1, root2);
	cout << (result ? "true" : "false") << endl;

	return 0;
}