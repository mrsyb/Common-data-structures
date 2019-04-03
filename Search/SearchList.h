#pragma once
#include<assert.h>
const int DefaultSize = 100;

template <typename K,typename E>
struct DataNode
{
	DataNode(K key,E value):Key(key),Other(value){}
	DataNode(DataNode<K, E>& node) { Key = node.Key; Other = node.Other; }
	void SetKey(K key) { Key = key; }
	K GetKey() { return Key; }
	E GetValue() { return Other; }

private:
	K Key;
	E Other;//自定义拷贝构造函数
};

template<typename K,typename E>
class SearchList {
	SearchList(int SZ = DefaultSize);
	~SearchList() { delete[] Element; }
	bool Insert(DataNode<K,E>& node);
	bool Delete(K key);
	int SeqSearch(K key);//使用监视哨
	int RecursionSearch(K key, int loc = 0);

private:
	DataNode<K, E>* Element;
	int MaxSize;
	int CurrentSize;
};