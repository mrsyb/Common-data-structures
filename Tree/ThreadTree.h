#pragma once
#include <cstdlib>


template<class T>
struct  ThreadNode
{
	int LTag, RTag;
	ThreadNode<T>* LeftChild, *RightChild;
	T Data;
	ThreadNode(const T Item) :Data(Item), LTag(0), RTag(0), LeftChild(NULL), RightChild(NULL) {}
};

template<class T>
class ThreadTree
{
public:
	ThreadTree() :Root(NULL) {}
	~ThreadTree() { delete Root; }
	ThreadTree<T>* CreatInThread();
	ThreadNode<T>* First(ThreadNode<T>* Current);
	ThreadNode<T>* Last(ThreadNode<T>* Current);
	ThreadNode<T>* Next(ThreadNode<T>* Current);
	ThreadNode<T>* Piror(ThreadNode<T>* Current);
	void InOrder(void(*Visit)(ThreadNode<T>* ));
	void PreOrder(void(*Visit)(ThreadNode<T>* ));
	void PostOrder(void(*Visit)(ThreadNode<T>* ));
protected:
	ThreadNode<T>* Root;
	void CreatInThread(ThreadNode<T>* Current, ThreadNode<T>* Pre);
	ThreadNode<T>* Parent(ThreadNode<T>* t);
};



