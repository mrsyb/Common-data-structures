#include "SortedList.h"

template<typename K, typename E>
bool SortedList<K, E>::Insert(DataNode<K, E>& node)
{
	if (this->CurrentSize >= this->MaxSize)
		return false;
	int j = 0;
	for (int i = this->CurrentSize - 1; i >= 0; i--)
	{
		if (this->Element[i].Key > node.Key)
		{
			j = i;
		}
	}
	for (int k = this->CurrentSize; k >= j; k--)
	{
		this->Element[k + 1] = this->Element[k];
	}
	this->Element[j] = node;
	return true;
}

template<typename K, typename E>
int SortedList<K, E>::BinarySearch(K key)
{
	int high = this->CurrentSize - 1,low = 0,mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key > this->Element[mid].Key)
		{
			low = mid + 1;
		}
		else if(key < this->Element[mid])
		{
			high = mid - 1;
		}
		else {
			return mid + 1;
		}
	}
	return -1;
}

template<typename K, typename E>
int SortedList<K, E>::RecursionBinarySearch(K key,int low,int high)
{
	int mid = (low+high)/2;
	if (low >= high)return 0;
	if (key > this->Element[mid].Key)
		RecursionBinarySearch(key, mid + 1, high);
	else if(key < this->Element[mid].Key){
		RecursionBinarySearch(key, low, mid-1);
	}else{
		return mid + 1;
	}
}
