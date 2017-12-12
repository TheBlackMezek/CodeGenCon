#pragma once


template<typename T>
struct treeNode
{
	T keyValue;
	treeNode<T>* left;
	treeNode<T>* right;
};


template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	BinaryTree(const BinaryTree& other);
	BinaryTree(const treeNode<T>* other);
	BinaryTree& operator=(const BinaryTree& other);

	void insert(int key);
	const treeNode<T>* search(int key);
	void destroyTree();



private:

	treeNode<T>* root;

	void destroyTree(treeNode<T>* node);
	void insert(int key, treeNode<T>* node);
	treeNode<T>* search(int key, treeNode<T>* node);
	treeNode<T>* copyNodes(const treeNode<T>* node);
};



template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}


template<typename T>
BinaryTree<T>::~BinaryTree()
{
	destroyTree();
}


template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
{
	root = copyNodes(other.root);
}
template<typename T>
BinaryTree<T>::BinaryTree(const treeNode<T>* other)
{
	root = copyNodes(other);
}
template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other)
{
	destroyTree();
	root = copyNodes(other.root);
	return *this;
}


template<typename T>
void BinaryTree<T>::insert(int key)
{
	if (root != nullptr)
	{
		insert(key, root);
	}
	else
	{
		root = new treeNode<T>;
		root->keyValue = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}
template<typename T>
const treeNode<T>* BinaryTree<T>::search(int key)
{
	return search(key, root);
}
template<typename T>
void BinaryTree<T>::destroyTree()
{
	destroyTree(root);
	root = nullptr;
}


template<typename T>
void BinaryTree<T>::destroyTree(treeNode<T>* node)
{
	if (node)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}
template<typename T>
void BinaryTree<T>::insert(int key, treeNode<T>* node)
{
	if (key < node->keyValue)
	{
		if (node->left != nullptr)
		{
			insert(key, node->left);
		}
		else
		{
			node->left = new treeNode<T>;
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
			node->right = new treeNode<T>;
			node->right->keyValue = key;
			node->right->left = nullptr;
			node->right->right = nullptr;
		}
	}
}
template<typename T>
treeNode<T>* BinaryTree<T>::search(int key, treeNode<T>* node)
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
template<typename T>
treeNode<T>* BinaryTree<T>::copyNodes(const treeNode<T>* node)
{
	if (node != nullptr)
	{
		treeNode<T>* newNode = new treeNode<T>;
		newNode->keyValue = node->keyValue;
		newNode->left = copyNodes(node->left);
		newNode->right = copyNodes(node->right);
		return newNode;
	}
	else
	{
		return nullptr;
	}
}
