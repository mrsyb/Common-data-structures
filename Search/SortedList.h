#pragma once
#include "SearchList.h"

template<typename K,typename E>
class SortedList :public SearchList<K,E>
{
public:
	SortedList(int SZ = DefaultSize) :SearchList(SZ) {}
	~SortedList();
	bool Insert(DataNode<K,E>& node)override;
	int BinarySearch(K key);
	int RecursionBinarySearch(K key, int low, int high);
};


