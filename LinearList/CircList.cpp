#include "CircList.h"

template<class T>
int CircList<T>::Length() const
{
	int i = 0;
	CircLinkNode<T> p = this->first->link;
	while (p->link != this->first)
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
	while (this->first->link != this->first)
	{
		p = this->first->link;
		this->first = p->link;
		delete p;
	}
}

template<class T>
CircLinkNode<T>*  CircList<T>::Seach(T x)
{
	if (this->first->link == this->first)
		return;

	CircLinkNode<T>* p = this->first->link;
	while (p->link != this->first)
	{
		if (p->data == x)
			return p;
		p = p->link;
	}
	return nullptr;
}

template<class T>
CircLinkNode<T>* CircList<T>::Locate(int i)
{
	CircLinkNode<T>* p = this->first;
	int Index = 0;

	if (i == 0) { return this->first; }

	while (p->link != this->first)
	{
		if (i == Index )
			return p;
		p = p->link;
	}
	return nullptr;
}
template<class T>
T CircList<T>::GetData(int i)
{
	return Locate(i)->data;
}
template<class T>
void CircList<T>::SetData(int i, T & d)
{
	d = Locate(i)->data;
}
template<class T>
bool CircList<T>::Insert(int i, const T & x)
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
bool CircList<T>::Remove(int i, T & x)
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