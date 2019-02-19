#pragma once
const MaxSize = 50;
template <class T >
struct SLinkNode
{
	T data;
	int link;
};

template<class T>
class StaticList
{
	SLinkNode<T> elem[MaxSize];
	int avil;
public:
	void InitList();
	int Length();
	int Search(T x);
	int Locate(int i);
	bool Append(T x);
	bool Insert(int i, T x);
	bool Remove(int i);
	bool IsEmpty();
};


