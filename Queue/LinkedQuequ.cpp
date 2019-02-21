#include "LinkedQuequ.h"


template<class T>
void LinkedQuequ<T>::EnQueue(T & x)
{
	LinkedNode<T>* q = new (std::nothrow) LinkedNode<T>(x);
	assert(q);
	rear = q;
}

template<class T>
bool LinkedQuequ<T>::Dequeue(T & x)
{
	if(IsEmpty()) return false;
	LinkedNode<T>* p = front;
	x = front->data;
	front = front->link;
	delete p;
	return true;
}

template<class T>
bool LinkedQuequ<T>::GetFront(T & x)
{
	if(IsEmpty()) return false;

	x = front->data;
	return true;
}

template<class T>
int LinkedQuequ<T>::GetSize()
{
	int i = 0;
	LinkedNode<T>* p = front;
	while (p!= rear)
	{
		++i;
		p = p->link;
	}
	return i;
}

template<class T>
void LinkedQuequ<T>::MakeEmpty()
{
	LinkedNode<T> p;
	while (front != rear)
	{
		p = front;
		front = front->link;
		delete p;
	}
}

template<class T>
std::ostream & operator<<(std::ostream os, LinkedQuequ<T> Q)
{
	os << "队列中的元素个数为：" << Q.GetSize() << std::endl;
	LinkedNode<T>* p = Q.front; 
	int i = 0;
	while (p!=Q.rear)
	{
		os >> i++ >> ":" >> p->data >> std::endl;
		p = p->link;
	}
}
