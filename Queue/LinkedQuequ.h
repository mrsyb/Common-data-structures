#pragma once
#include "Queue.h"
#include <iostream>

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
#endif //!LINKEDNODE

template<class T>
class LinkedQuequ :public Queue<T>
{
public:
	LinkedQuequ() :rear(nullptr), front(nullptr) {}
	~LinkedQuequ() { MakeEmpty(); }

	virtual void EnQueue(T &x) override;
	virtual bool Dequeue(T &x) override;
	virtual bool GetFront(T &x) override;
	virtual bool IsEmpty() const override { return front == rear; }
	virtual bool IsFull() const override {}
	virtual int GetSize() override;

	void MakeEmpty();
	friend std::ostream& operator<<(std::ostream os, LinkedQuequ<T> Q);
protected:
	LinkedNode<T>* front, *rear;
};

