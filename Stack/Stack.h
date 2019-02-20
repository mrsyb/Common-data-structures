#pragma once
const int Maxsize = 50;
template <class T>
class Stack
{
	Stack();
	virtual void Push(const T& x) = 0;
	virtual bool Pop(T& x) = 0;
	virtual bool GetTop(T& x)const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int GetSize()const = 0;
};