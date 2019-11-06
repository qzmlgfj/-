#include "Tree.hpp"
int result;

int main()
{
	BinaryTree<char> tree;

	tree.buildBinaryTree();

	tree.preTraversal(tree.root);
	cout << endl;

	tree.inTraversal(tree.root);
	cout << endl;

	tree.postTraversal(tree.root);
	cout << endl;

	system("PAUSE");
	return 0;
}