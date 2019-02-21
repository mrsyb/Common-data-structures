#pragma once
#include "Queue.h"
#include <assert.h>
#include <iostream>

template<class T>
class SeqQueue :public Queue<T>
{
public:
	SeqQueue(int SZ = 10);
	~SeqQueue() { delete[] elements; };

	virtual void EnQueue(T &x) override;
	virtual bool Dequeue(T &x) override;
	virtual bool GetFront(T &x) override { return elements[front]; }
	virtual bool IsEmpty()const override { return front == rear; }
	virtual bool IsFull()const override { return (front + 1) % MaxSize = rear; }
	virtual int GetSize() override;

	void MakeEmpty() { front = rear = 0; };
	friend std::ostream& operator <<(std::ostream os, SeqQueue<T> queue);
private:
	int MaxSize;
	int front, rear;
	T* elements;
};



