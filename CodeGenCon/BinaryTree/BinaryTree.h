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

	BinaryTree(const BinaryTree& other);
	BinaryTree(const treeNode* other);
	BinaryTree& operator=(const BinaryTree& other);

	void insert(int key);
	const treeNode* search(int key);
	void destroyTree();



private:

	treeNode* root;

	void destroyTree(treeNode* node);
	void insert(int key, treeNode* node);
	treeNode* search(int key, treeNode* node);
	treeNode* copyNodes(const treeNode* node);
};

