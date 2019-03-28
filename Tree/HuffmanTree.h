#pragma once
#include "../MinHeap/MInHeap.h"
#include <cstdlib>

template<class T>
struct HuffmanNode 
{
	T data;
	HuffmanNode* leftChild, *rightChild, *parent;
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL) {}
	HuffmanNode(T data, HuffmanNode* left = NULL, HuffmanNode* right = NULL, HuffmanNode* parent = NULL) :data(data), leftChild(left),
				rightChild(right) ,parent(parent){}
	bool operator <=(HuffmanNode& R) { return data <= R.data; }
	bool operator >(HuffmanNode& R) { return data > R.data; }
};

template<class T>
class HuffmanTree
{
public:
	HuffmanTree(float w[],int n);
	~HuffmanTree() { deleteTree(Root); }
protected:
	HuffmanNode<T>* Root;
	void deleteTree(HuffmanNode<T>* t);
	void mergeTree(HuffmanNode<T>& ht1, HuffmanNode<T>& ht2, HuffmanNode<T>* &parent);
};



