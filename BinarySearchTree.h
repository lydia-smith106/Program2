#ifndef BINARYSEARCHTREE_
#define BINARYSEARCHTREE_

#include "BinaryNode.h"

#include <iostream>

using namespace std;

template<class T>
class BinarySearchTree
{

private:
	//binary pointer to root
	BinaryNode<T>* root;

	int size;

	int compares;
	//binary tree private methods

	//private method to add leaf to tree
	void AddLeafPrivate(T data, BinaryNode<T>* ptr);

	void PrintInOrderPrivate(BinaryNode<T>* ptr)
	{

		if (root != nullptr)
		{
			if (ptr->left != nullptr)
			{
				PrintInOrderPrivate(ptr->left);

			}
			cout << ptr->data << " ";
			if (ptr->right != nullptr)
			{
				PrintInOrderPrivate(ptr->right);

			}

		}
		else
		{
			cout << "The tree is empty\n";
		}
	};

	//private method to search for data
	BinaryNode<T>* FindPrivate(T data, BinaryNode<T>* ptr);

	//private method to remoove node from a tree
	void RemoveNodePrivate(T data, BinaryNode<T>*& t);

public:

	//Binary Search Tree public methods

	//Binary Search Tree constructor
	BinarySearchTree();

	//method to create node 
	BinaryNode<T>* CreateLeaf(T data);

	//method to add a leaf to binary tree
	void AddLeaf(T data);

	void PrintInOrder()
	{
		PrintInOrderPrivate(root);

	};

	//method to search for pointer to data in tree
	BinaryNode<T>* Find(T data);

	//method to find minimum value in a tree
	BinaryNode<T>* findMin(BinaryNode<T>* ptr);

	//method to remove a node from a tree
	void RemoveNode(T data);

	int getSize() { return size; }

	int getCompares() { return compares; }


};

#endif