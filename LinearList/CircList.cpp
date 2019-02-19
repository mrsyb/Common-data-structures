#include "CircList.h"

template <class T>
CircList<T>::~CircList()
{
	delete[] fist;
	delete[] last;
}

template<class T>
int CircList<T>::Length() const
{
	int i = 0;
	CircLinkNode<T> p = fist->link;
	while (p->link != fist)
	{
		i++;
		p = p->link;
	}
	return i;
}

template<class T>
void CircList<T>::MakeEmepty()
{
	CircLinkNode<T> p;
	while (fist->link != fist)
	{
		p = fist->link;
		fist = p->link;
		delete p;
	}
}

template<class T>
CircLinkNode<T>* Seach(T x)
{
	if (fist->link == first)
		return;

	CircLinkNode<T>* p = frist->link;
	while (p->link != fist)
	{
		if (p->data == x)
			return p;
		p = p->link;
	}
	return nullptr;
}

template<class T>
CircLinkNode<T>* Locate(int i)
{
	CircLinkNode<T>* p = frist;
	int Index = 0;

	if (i == 0) { return first; }

	while (p->link != fist)
	{
		if (i == Index )
			return p;
		p = p->link;
	}
	return nullptr;
}
template<class T>
T GetData(int i)
{
	return Locate(i)->data;
}
template<class T>
void SetData(int i, T & d)
{
	d = Locate(i)->data;
}
template<class T>
bool Insert(int i, const T & x)
{
	CircLinkNode<T>* CurrentNode;
	CircLinkNode<T>* NewNode = new CircLinkNode<T>(x);

	CurrentNode = Locate(i);
 	if (CurrentNode)
	{
		NewNode->link = CurrentNode->link;
		CurrentNode->link = NewNode;
		return true;
	}
	return false;
}
template<class T>
bool Remove(int i, T & x)
{
	CircLinkNode<T>* CurrentNode;
	CircLinkNode<T>* PreNode;

	PreNode = Locate(i-1);
	if (PreNode != nullptr||PreNode->link != nullptr)
	{
		CurrentNode = PreNode->link;
		PreNode->link = CurrentNode->link;
		delete CurrentNode;
		return true;
	}
	return false;
}
