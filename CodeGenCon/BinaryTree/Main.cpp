#include <iostream>
#include <cassert>

#include "BinaryTree.h"


template<typename T>
void printTree(const treeNode<T>* node, int iteration);

int main()
{
	BinaryTree<int> t;
	int rootNum = 100;
	t.insert(rootNum);

	t.insert(150);
	t.insert(50);

	BinaryTree<int> tt(t);
	BinaryTree<int> ttt = t;


	const treeNode<int>* n = t.search(rootNum);
	printTree(n, 0);

	assert(n->keyValue == rootNum);
	assert(n->left->keyValue == 50);
	assert(n->right->keyValue == 150);

	t.destroyTree();

	assert(t.search(rootNum) == nullptr);


	const treeNode<int>* nn = tt.search(rootNum);
	printTree(nn, 0);

	assert(nn->keyValue == rootNum);
	assert(nn->left->keyValue == 50);
	assert(nn->right->keyValue == 150);


	const treeNode<int>* nnn = ttt.search(rootNum);
	printTree(nnn, 0);

	assert(nnn->keyValue == rootNum);
	assert(nnn->left->keyValue == 50);
	assert(nnn->right->keyValue == 150);


	BinaryTree<char> c;
	char rootChar = 'c';
	c.insert(rootChar);

	c.insert('A');
	c.insert('a');
	c.insert('1');
	c.insert('+');
	c.insert('t');

	const treeNode<char>* cn = c.search(rootChar);

	assert(cn->keyValue == 'c');
	assert(cn->left->keyValue == 'A');
	assert(cn->right->keyValue == 't');

	printTree(cn, 0);



	std::cin.get();

	return 0;
}


template<typename T>
void printTree(const treeNode<T>* node, int iteration)
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
