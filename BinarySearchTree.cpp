#include <iostream>
#include <cstdlib>

#include "BinarySearchTree.h"

using namespace std;

//binary tree method implementations

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	size = 0;
	compares = 0;
};

template<class T>
BinaryNode<T>* BinarySearchTree<T>::CreateLeaf(T data)
{
	BinaryNode<T>* n = new BinaryNode<T>;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	size++;

	return n;


};

template<class T>
void BinarySearchTree<T>::AddLeaf(T data)
{
	AddLeafPrivate(data, root);

};

template<class T>
void BinarySearchTree<T>::AddLeafPrivate(T data, BinaryNode<T>* ptr)
{

	if (root == nullptr)
	{
		root = CreateLeaf(data);


	}
	else if ((data.compare(ptr->data)) < 0)
	{
		if (ptr->left != nullptr)
		{
			AddLeafPrivate(data, ptr->left);

		}
		else
		{
			ptr->left = CreateLeaf(data);

		}
	}
	else if ((data.compare(ptr->data)) > 0)
	{
		if (ptr->right != nullptr)
		{
			AddLeafPrivate(data, ptr->right);

		}
		else
		{
			ptr->right = CreateLeaf(data);
		}
	}

	else
	{
		cout << "already added" << endl;

	}

};

template<class T>
BinaryNode<T>* BinarySearchTree<T>::Find(T data)
{
	return FindPrivate(data, root);
};

template<class T>
BinaryNode<T>* BinarySearchTree<T>::FindPrivate(T data, BinaryNode<T>* ptr)
{

	if (ptr != nullptr)
	{
		if ((data.compare(ptr->data)) == 0)
		{
			return ptr;

		}
		else
		{
			if ((data.compare(ptr->data)) < 0)
			{
				return FindPrivate(data, ptr->left);

			}
			else
			{
				return FindPrivate(data, ptr->right);

			}

		}

	}
	else
	{
		return nullptr;

	}


};

template<class T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* ptr)
{
	if (ptr == nullptr)
	{
		return nullptr;

	}
	else if (ptr->left == nullptr)
	{
		return ptr;
	}

	return findMin(ptr->left);

};
template<class T>
void BinarySearchTree<T>::RemoveNode(T data)
{

	return RemoveNodePrivate(data, root);

};

template<class T>
void BinarySearchTree<T>::RemoveNodePrivate(T data, BinaryNode<T>*& t)
{
	if (t == nullptr) { return; }
	if ((data.compare(t->data)) < 0)
	{
		RemoveNodePrivate(data, t->left);
	}
	else if ((data.compare(t->data)) > 0)
	{
		RemoveNodePrivate(data, t->right);
	}
	else
	{
		BinaryNode<T>* oldNode;
		if (t->left == nullptr)
		{
			oldNode = t;
			t = t->right;
			delete oldNode;
			size--;
			return;

		}
		else if (t->right == nullptr)
		{
			oldNode = t;
			t = t->left;
			delete oldNode;
			size--;
			return;

		}

		oldNode = findMin(t->right);
		t->data = oldNode->data;
		RemoveNodePrivate(t->data, t->right);
	}

};



