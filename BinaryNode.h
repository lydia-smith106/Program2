#ifndef BINARYNODE_
#define BINARYNODE_

// Node class for binary tree
template<class T>

class BinaryNode
{

public:
	//each node contains data, and left and right pointers
	T data;
	BinaryNode<T>* left;
	BinaryNode<T>* right;

	//constructor for binary node
	BinaryNode(T d)
		: data(d), left(nullptr), right(nullptr) {};

	BinaryNode()
		: data(" "), left(nullptr), right(nullptr) {};

	//destructor????

};

#endif

