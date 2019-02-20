#include "SeqStack.h"

template<class T>
SeqStack<T>::SeqStack(int SZ):MaxSize(SZ),top(-1)
{
	elements = new (std::nothrow) T[MaxSize];
	assert(elements);
}

template<class T>
void SeqStack<T>::OverFlowProcess()
{
	MaxSize += stackIncreament;
	T NewElements = new (std::nothrow) T[MaxSize];
	assert(NewElements);
	while (*NewElements++ = *elements++) {}
	delete[]elements;
	elements = NewElements;
}

template<class T>
void SeqStack<T>::Push(const T & x)
{
	if (IsFull()) OverFlowProcess();
	elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T & x)
{
	if (IsEmpty())return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::GetTop(T & x) const
{
	if (IsEmpty())return false;
	x = elements[top];
	return true;
}

template<class T>
std::ostream & operator<<(std::ostream & os, SeqStack<T>& Seq)
{
	os << "top == " << Seq.top <<std::endl;
	for (int i = 0;i<Seq.top;i++)
	{
		os << i << ":" << Seq.elements[i] << std::endl;
	}
	return os;
}
