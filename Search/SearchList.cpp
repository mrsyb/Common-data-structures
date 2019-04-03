#include "SearchList.h"
template<typename K,typename E>
SearchList<K, E>::SearchList(int SZ):MaxSize(SZ), CurrentSize(0)
{
	Element = new DataNode<K,E>[MaxSize];
	assert(Element);
}

template<typename K, typename E>
bool SearchList<K, E>::Insert(DataNode<K,E>& node)
{
	if (CurrentSize == MaxSize)
		return false;
	DataNode<K, E> temp(node);
	assert(temp);
	Element[++CurrentSize] = temp;
	return false;
}

template<typename K, typename E>
bool SearchList<K, E>::Delete(K key)
{
	int i = 0;
	if (SeqSearch(key) == -1)
		return false;
	while (i < CurrentSize)
	{
		Element[i + 1] = Element[i];
		++i;
	}
	return true;
}

template<typename K, typename E>
int SearchList<K, E>::SeqSearch(K key)
{
	int i = 0;
	Element[CurrentSize].Key = key;
	while (Element[i].key != key)
	{
		i++;
	}
	return i == CurrentSize?-1:i;
}

template<typename K, typename E>
int SearchList<K, E>::RecursionSearch(K key,int loc)
{
	if (loc == CurrentSize)
		return 0;
	else if (Element[loc].Key == key)
		return loc;
	else
		return RecursionSearch(key, loc + 1);
}
