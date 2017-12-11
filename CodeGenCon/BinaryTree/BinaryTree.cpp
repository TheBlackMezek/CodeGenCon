#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
	root = nullptr;
}


BinaryTree::~BinaryTree()
{
	destroyTree();
}


void BinaryTree::insert(int key)
{
	if (root != nullptr)
	{
		insert(key, root);
	}
	else
	{
		root = new treeNode;
		root->keyValue = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}
treeNode* BinaryTree::search(int key)
{
	return search(key, root);
}
void BinaryTree::destroyTree()
{
	destroyTree(root);
}


void BinaryTree::destroyTree(treeNode* node)
{
	if (node)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}
void BinaryTree::insert(int key, treeNode* node)
{
	if (key < node->keyValue)
	{
		if (node->left != nullptr)
		{
			insert(key, node->left);
		}
		else
		{
			node->left = new treeNode;
			node->left->keyValue = key;
			node->left->left = nullptr;
			node->left->right = nullptr;
		}
	}
	else if (key >= node->keyValue)
	{
		if (node->right != nullptr)
		{
			insert(key, node->right);
		}
		else
		{
			node->right = new treeNode;
			node->right->keyValue = key;
			node->right->left = nullptr;
			node->right->right = nullptr;
		}
	}
}
treeNode* BinaryTree::search(int key, treeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	
	if (key == node->keyValue)
	{
		return node;
	}
	else if (key < node->keyValue)
	{
		return search(key, node->left);
	}
	else
	{
		return search(key, node->right);
	}
}
