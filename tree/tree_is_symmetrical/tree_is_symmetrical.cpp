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

bool tree_is_symmetrical(tree_node* root1, tree_node* root2)
{
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->data != root2->data) return false;

    return tree_is_symmetrical(root1->left, root2->right)
                && tree_is_symmetrical(root1->right, root2->left);
}

int main()
{
	tree_node* root1;

	root1 = new tree_node(1);
	root1->left = new tree_node(2);
	root1->right = new tree_node(2);
	root1->left->left = new tree_node(4);
	root1->left->right = new tree_node(5);
	root1->right->left = new tree_node(5);
	root1->right->right = new tree_node(4);
	//root1->left->left->left = new tree_node(8);
	//root1->left->left->right = new tree_node(9);

	//tree_node* root2;
	//root2 = new tree_node(4);
	//root2->left = new tree_node(8);
	//root2->right = new tree_node(9);

	bool result = tree_is_symmetrical(root1->left, root1->right);
	cout << (result ? "true" : "false") << endl;

	return 0;
}