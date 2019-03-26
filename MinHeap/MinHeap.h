#pragma once
#include <cstdlib>
#include "../Queue/PQueue.h"

#define  DefaultSize 10

template<class T>
class MinHeap :public PQueue<T>
{
public:
	MinHeap(int SZ = DefaultSize);
	MinHeap(T arr[], int n);
	~MinHeap() { delete *Heap; }
	bool Insert(const T&x);
	bool RemoveMin(T& x);
	bool ISEmpty()const { return CurrentSize == 0 ? true:false; }
	bool IsFull()const { return CurrentSize == MaxHeapSize ? true : false; }
	void MakeEmpty() { CurrentSize = 0; }
private:
	T *Heap;
	int CurrentSize;
	int MaxHeapSize;
	void SiftDown(int start, int m);
	void SiftUp(int start);
};
