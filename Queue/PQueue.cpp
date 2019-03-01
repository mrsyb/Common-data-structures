#include "PQueue.h"


template <class T>
PQueue<T>::PQueue(int SZ /*= MaxSize*/):Count(0)
{
	PQElements = new(std::nothrow) T[SZ];
	assert(PQElements!=nullptr);
}

template <class T>
bool PQueue<T>::RemoveMin(T& x)
{
	if (Count == 0) return false;
	x = PQElements[0];
	--Count;
	int q = Count;
	while (q != 0)
	{
		PQElements[q-1] = PQElements[q];
		q--;
	}
	return true;
}

template <class T>
bool PQueue<T>::GetFront(T& x) const
{
	if (Count == 0) return false;
	x = PQElements[0];
	return true;
}

template <class T>
void PQueue<T>::Adjuest()
{
	T rear = PQElements[Count - 1],i;

	for (i= Count-2;i>0;i--)
	{
		if (PQElements[i] <= rear)
		{
			break;
		}
		else
		{
			PQElements[i + 1] = PQElements[i];
		}
	}
	PQElements[i + 1] = rear;
}

template <class T>
bool PQueue<T>::Insert(const T& x)
{
	if (Count == MaxSize)
	{
		return false;
	}
	*PQElements++ = x;
	++Count;
	/*
	PQElement[++Count]£»
	*/
	Adjuest();
	return true;
}
