#pragma once


struct treeNode
{
	int keyValue;
	treeNode* left;
	treeNode* right;
};


class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int key);
	treeNode* search(int key);
	void destroyTree();



private:

	treeNode* root;

	void destroyTree(treeNode* node);
	void insert(int key, treeNode* node);
	treeNode* search(int key, treeNode* node);
};

