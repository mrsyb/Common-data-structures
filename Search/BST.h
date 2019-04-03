#pragma once
#include <cstdlib>

template<typename T>
struct BSTNode{
	T Data;
	BSTNode<T>* left, *right;
	BSTNode(BSTNode<T>& p) { left = p->left; right = p->right; Data = p->Data; }
	BSTNode(T x, BSTNode<T>* L = NULL, BSTNode<T>* R = NULL):Data(x),left(L),right(R){}
	void SetData(T data) { Data = data; }
	T GetData() { return Data; }
};

template<class T>
class BST {
	BST():Root(NULL){}
	~BST() { MakeEmpty(); }
	void MakeEmpty(BSTNode<T>& node);
	bool Insert(T e,BSTNode<T>* &x);
	bool Remove(T k, BSTNode<T>* &x);
	BSTNode<T>* Min(BSTNode<T>* subTree);
	BSTNode<T>* BinarySearch(T key,BSTNode<T>* ptr);
private:
	BSTNode<T>* Root;
};

