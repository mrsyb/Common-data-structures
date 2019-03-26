#include "MinHeap.h"

template<class T>
MinHeap<T>::MinHeap(int SZ)
{
	MaxHeapSize = (SZ < DefaultSize) ? SZ : DefaultSize;
	Heap = new(std::nothrow) T[MaxHeapSize];
	if (Heap == NULL)
	{
		std::cout << "Memory allocation failure!" << std::endl;
		exit(1);
	}
	CurrentSize = 0;
}

template<class T>
inline MinHeap<T>::MinHeap(T arr[], int n)
{
	MaxHeapSize = (n > DefaultSize) ? DefaultSize : n;
	Heap = new(std::nothrow) T[MaxHeapSize];
	if (Heap == NULL)
	{
		std::cout << "Memory allocation failure!" << std::endl;
		exit(0);
	}
	while (*Heap = *arr != NULL) {}
	CurrentSize = n;
	int CurrentPos = (CurrentSize - 2) / 2;
	while (CurrentPos>=0)
	{
		SiftDown(CurrentPos, CurrentSize - 1);
		CurrentPos--;
	}
}

template<class T>
inline bool MinHeap<T>::Insert(const T & x)
{
	if (CurrentSize == MaxHeapSize)
	{
		std::cout << "Heap Full!" << std::endl;
		return false;
	}
	Heap[CurrentSize] = x;
	SiftUp(CurrentSize);
	++CurrentSize;
	return true;
}

template<class T>
inline bool MinHeap<T>::RemoveMin(T & x)
{
	if (CurrentSize == 0)
	{
		std::cout << "Heap Empty!" << std::endl;
		return false;
	}
	Heap[0] = Heap[CurrentSize-1];
	--CurrentSize;
	SiftDown(0, CurrentSize-1);
	return true;
}

template<class T>
inline void MinHeap<T>::SiftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	T temp = Heap[i];
	while (j<=m)
	{
		if (Heap[j] > Heap[j + 1])j++;
		if (Heap[i] > Heap[j]) 
		{
			Heap[i] = Heap[j];
			i = j; 
			j = j * 2 + 1;
		}
		else {
			break;
		}
	}
	Heap[i] = temp;

}

template<class T>
inline void MinHeap<T>::SiftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	T temp = Heap[j];
	while (i>0)
	{
		if (temp >= Heap[j]) break;
		else{
			Heap[j] = Heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	Heap[j] = temp;
}
