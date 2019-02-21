#include "SeqQueue.h"


template<class T>
SeqQueue<T>::SeqQueue(int SZ):MaxSize(SZ),front(0),rear(0)
{
	elements = new T[MaxSize];
	assert(elements);
}

template<class T>
void SeqQueue<T>::EnQueue(T &x)
{
	if (!IsFull())
	{
		elements[rear] = x;
		rear = (rear + 1) % MaxSize;
	}
		
}

template<class T>
bool SeqQueue<T>::Dequeue(T &x)
{
	if (!IsEmpty())
	{
		x = elements[front];
		front = (front + 1) % MaxSize;
		return true;
	}
	return false;
}

template<class T>
int SeqQueue<T>::GetSize()
{
	return (rear-front+MaxSize)%MaxSize;
}

template<class T>
std::ostream & operator<<(std::ostream os, SeqQueue<T> queue)
{
	os << "front =" << queue.front << "rear = " << queue.rear << std::endl;
	for (int i = queue.front;i!= queue.rear;(i++)%queue.MaxSize)
	{
		os << i << ":" << queue.elements[i]<<std::endl;
	}
	return os;
}
