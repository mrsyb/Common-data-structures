#pragma once
#include "SeqQueue.h"

template <class T>
class PQueue 
{
public:
	PQueue(int SZ = MaxSize);
	~PQueue() { delete[] PQElements; }
	bool GetFront(T& x)const;
	bool RemoveMin(T& x);
	bool Insert(const T& x);
	void MakeEmpty() { Count = 0; }
	bool IsEmpty() { return Count == 0; }
	bool IsFull() { return Count == MaxSize; }
	int GetSize(){return Count;}

private:
	T* PQElements;
	int Count;
	void Adjuest();
};


