#pragma once
#include "Stack.h"
#include <iostream>
#include <assert.h>

const int stackIncreament = 20;
template <class T>
class SeqStack :public Stack<T>
{
public:
	SeqStack(int SZ = 50);
	~SeqStack() { delete[] elements; }
	virtual void Push(const T& x) override;
	virtual bool Pop(T& x) override;
	virtual bool GetTop(T& x) const override;
	virtual bool IsEmpty() const override { return top == -1; }
	virtual bool IsFull() const override { return top == MaxSize - 1 ? true : false; }
	virtual int GetSize() const override { return top+1; }
	void MakeEmpty() { top = -1; }
	friend std::ostream& operator<<(std::ostream& os, SeqStack<T> & Seq);
private:
	T* elements;
	int MaxSize;
	int top;
	void OverFlowProcess();//栈的溢出处理
};


