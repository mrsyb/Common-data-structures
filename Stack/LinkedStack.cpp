#include "LinkedStack.h"

template<class T>
void LinkedStack<T>::Push(const T & x)
{
	LinkedNode<T>* NewNode = new LinkedNode<T>(x,top);
	assert(NewNode);
	top = NewNode;
}

template<class T>
bool LinkedStack<T>::Pop(T & x)
{
	if (IsEmpty()) return false;
	LinkedNode<T>* p = top;
	top = top->link;
	x = p->data;
	delete p;
	return true;
}

template<class T>
bool LinkedStack<T>::GetTop(T & x) const
{
	if (IsEmpty()) return false;
	x = top->data;
	return true;
}

template<class T>
int LinkedStack<T>::GetSize() const
{
	int i = 0;
	LinkedNode<T>* p = top;
	while (p!= nullptr)
	{
		i++;
		p = p->link;
	}
	return i;
}

template<class T>
void LinkedStack<T>::MakeEmpty()
{
	LinkedNode<T>* p;
	if (top != nullptr)
	{
		p = top;
		delete p;
		top = top->link;
	}
}