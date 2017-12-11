#include <iostream>
#include <cassert>

#include "BinaryTree.h"


void printTree(const treeNode* node, int iteration);

int main()
{
	BinaryTree t;
	int rootNum = 100;
	t.insert(rootNum);

	t.insert(150);
	t.insert(50);

	BinaryTree tt(t);
	BinaryTree ttt = t;


	const treeNode* n = t.search(rootNum);
	printTree(n, 0);

	assert(n->keyValue == rootNum);
	assert(n->left->keyValue == 50);
	assert(n->right->keyValue == 150);

	t.destroyTree();

	assert(t.search(rootNum) == nullptr);


	const treeNode* nn = tt.search(rootNum);
	printTree(nn, 0);

	assert(nn->keyValue == rootNum);
	assert(nn->left->keyValue == 50);
	assert(nn->right->keyValue == 150);


	const treeNode* nnn = ttt.search(rootNum);
	printTree(nnn, 0);

	assert(nnn->keyValue == rootNum);
	assert(nnn->left->keyValue == 50);
	assert(nnn->right->keyValue == 150);



	std::cin.get();

	return 0;
}


void printTree(const treeNode* node, int iteration)
{
	if (node != nullptr)
	{
		for (int i = 0; i < iteration; ++i)
		{
			std::cout << "#";
		}

		std::cout << node->keyValue << std::endl;

		++iteration;
		printTree(node->left, iteration);
		printTree(node->right, iteration);
	}
}
