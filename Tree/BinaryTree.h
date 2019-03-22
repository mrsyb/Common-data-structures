#pragma once
#include "Tree.h"
#include <cstdlib>
#include "../Queue/LinkedQuequ.h"
#include "../Stack/LinkedStack.h"

template <class T>
class BinaryTree
{
public:
	BinaryTree() :Root(NULL) {}
	//BinaryTree(T value) :RefValue(value), Root(NULL) {}
	BinaryTree(BinaryTree<T>& BT);
	~BinaryTree() { Destory(); }
	bool IsEmpty() { return Root == NULL ? true : false; }
	BinaryNode<T>* Parent(BinaryNode<T>* Current) { return (Root = NULL || Root == Current) ? NULL : Parent(Root, Current); }
	BinaryNode<T>* LeftChild(BinaryNode<T>* Current) { return (Current == NULL) ? NULL : Current->Left; }
	BinaryNode<T>* RightChild(BinaryNode<T>* Current) { return (Current == NULL) ? NULL : Current->Right; }
	BinaryNode<T>* GetRoot() { return Root; }
	void RecursionPreOrder(void(*Visit)(BinaryNode<T>* Current)) { RecursionPreOrder(Root, Visit); }
	void RecursionInOrder(void(*Visit)(BinaryNode<T>* Current)) { RecursionInOrder(Root, Visit); }
	void RecursionPostOrder(void(*Visit)(BinaryNode<T>* Current)) { RecursionPostOrder(Root, Visit); }
	void NoRecuPreOrder(void(*Visit)(BinaryNode<T>* Current)) { NoRecuPreOrder(Root, Visit); }
	void NoRecuInOrder(void(*Visit)(BinaryNode<T>* Current)) { NoRecuInOrder(Root, Visit); }
	void NoRecuPostOrder(void(*Visit)(BinaryNode<T>* Current)) { NoRecuPostOrder(Root, Visit); }
	void LevelOrder(void(*Visit)(BinaryNode<T>* Current)) { LevelOrder(Root, Visit); }
	int Hight() { return Hight(Root); };
	int Size() { return Size(Root); }
	void Destory() { Destory(Root); };
	int Insert(const T& Item);
	BinaryNode<T>* Find(const T& Item)	const;
	
	

protected:
	BinaryNode<T>* Root;
	BinaryNode<T>* Parent(BinaryNode<T>* SubTree, BinaryNode<T>* Current);
	void RecursionPreOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void RecursionInOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void RecursionPostOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void NoRecuPreOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void NoRecuInOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void NoRecuPostOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	//////////////////////////////////////////////////////////////////////////
	void NoRecuPreOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void NoRecuInOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	void NoRecuPostOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current));
	//////////////////////////////////////////////////////////////////////////
	void LevelOrder(BinaryNode<T>* root, void(*Visit)(BinaryNode<T>* Current));
	void Destory(BinaryNode<T>* root);
	int Hight(BinaryNode<T>* Node);
	int Size(BinaryNode<T>* root);
};


