#pragma once
const int MaxSize = 50;
template <class T>
class Queue 
{
public:
	Queue();
	~Queue();
	virtual void EnQueue(T &x) = 0;
	virtual bool Dequeue(T &x) = 0;
	virtual bool GetFront(T &x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual int GetSize() = 0;
};