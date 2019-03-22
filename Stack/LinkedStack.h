#pragma once
#include "Stack.h"

#ifndef LINKEDNODE
#define LINKEDNODE
template<class T>
struct LinkedNode
{
	T data;
	LinkedNode<T> *link;
	LinkedNode(LinkedNode<T> *ptr = nullptr) :link(ptr) {};
	LinkedNode(const T& item, LinkedNode<T> *ptr = nullptr) :data(item), link(ptr) {}
};
#endif // !LINKEDNODE

template <class T>
class LinkedStack :public Stack<T>
{
public:
	LinkedStack():top(nullptr) {};
	~LinkedStack() { MakeEmpty(); };
	virtual void Push(const T& x) override;
	virtual bool Pop(T& x) override;
	virtual bool GetTop(T& x) const override;
	virtual bool IsEmpty() const override { top == nullptr ? false : true; }
	virtual bool IsFull() const override {}
	virtual int GetSize() const override;
	void MakeEmpty();

private:
	LinkedNode<T>* top;
};