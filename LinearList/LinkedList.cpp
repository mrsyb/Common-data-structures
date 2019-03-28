#include "LinkedList.h"


template<class T>
List<T>::List(List<T> &L)
{
	T value;
	LinkedNode<T>* srcptr = L.GetHead();
	LinkedNode<T>* desptr = first = new LinkedNode<T>;
	while (desptr->link != nullptr)
	{
		value = srcptr->link->data;
		desptr->link = new LinkedNode<T>(value);
		srcptr = srcptr->link;
		desptr = desptr->link;
	}
	desptr->link = nullptr;
}

template<class T>
int List<T>::Length() const 
{
	int count = 0;
	LinkedNode<T>* p = first->link;
	while (p->link != nullptr)
	{
		p = p->link;
		count++;
	}
	return count;
}

template<class T>
LinkedNode<T>* List<T>::MySearch(const T& x) const
{
	LinkedNode<T>* p = first->link;
	while (p->link!= nullptr)
	{
		if(p->data == x)
			return p;
		p = p->link;
	}
	return nullptr;
}

template<class T>
LinkedNode<T>* List<T>::Locate(int i)
{
	int count = 0;
	LinkedNode<T>* p = this->first->link;
	while (count < i&&p!= nullptr)
	{
		p = p->link;
		count++;
	}
	return p;
}

template<class T>
bool List<T>::GetData(int i, T& x)
{
	if (i < 0)return false;
	if (Locate(i) != nullptr)
	{
		x = Locate(i)->data;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void List<T>::SetData(int i, const T& x) 
{
	if (i < 0)return ;
	LinkedNode<T>* p =  Locate(i);
	if (p->link == nullptr)
		return;
	p->data = x;
}

template<class T>
bool List<T>::Remove(int i, T&x) 
{
	LinkedNode<T>* pre = Locate(i - 1);
	LinkedNode<T>* current = Locate(i);
	if (pre == nullptr || pre->link == nullptr)
		return false;
	pre->link = current->link;
	x = current->data;
	delete current;
	return true;

}

template<class T>
bool List<T>::Insert(int i,const T & x)
{
	LinkedNode<T>* current = Locate(i);
	if (current == nullptr)
		return false;
	LinkedNode<T>* NewNode = new LinkedNode<T>(x);
	if (NewNode == nullptr) { return false; }
	NewNode->link = current->link;
	current->link = NewNode;
	return true;
}

template<class T>
bool List<T>::IsEmpty() 
{
	if (first->link == nullptr)
		return true;
	return false;
}

template<class T>
void List<T>::Output() 
{
	LinkedNode<T>* p = first->link;
	while (p != nullptr)
	{
		std::cout <<"#:"<< p->data << std::endl;
		p = p->link;
	}
}

template<class T>
void List<T>::clear()
{
	LinkedNode<T>* head = first->link;
	LinkedNode<T>* del = nullptr;
	while (head != nullptr)
	{
		del = head;
		head = head->link;
		delete del;
	}
}

template<class T>
void List<T>::InputFront(T endFlag)
{
	LinkedNode<T>* newNode;
	T var;
	clear();
	std::cin >> var;
	while (var != endFlag)
	{
		newNode = new(std::nothrow) LinkedNode<T>(var);
		if (newNode)
		{
			newNode->link = first->link;
			first->link = newNode;
			std::cin >> var;
		}
	}
}

template<class T>
void List<T>::InputRear(T endFlag)
{
	LinkedNode<T>* newNode;
	LinkedNode<T>* rear;
	T var;
	clear();
	std::cin >> var;
	rear = first;
	while (var!= endFlag)
	{
		newNode = new (std::nothrow)LinkedNode<T>(var);
		if (newNode != nullptr)
		{
			rear->link = newNode;
			rear = newNode;
			std::cin >> var;
		}
	}
	rear->link = nullptr;
}

template<class T>
List<T>& List<T>::operator =(List<T> &L)
{
	LinkedNode<T>* desptr = L.GetHead();
	LinkedNode<T>* srcptr = this->first;
	if (this->first == desptr)
		return *this;
	this->clear();
	while (desptr->link!= nullptr)
	{
		LinkedNode<T>* newNode = new LinkedNode<T>(desptr->data);
		srcptr->link = newNode;
		srcptr = newNode;
		desptr = desptr->link;
	}
	srcptr->link == nullptr;
	return *this;
}

