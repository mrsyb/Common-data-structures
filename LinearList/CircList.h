#pragma once
#include "LinearList.h"

template <class T>
struct CircLinkNode {
	T data;
	CircLinkNode<T>* link;
	CircLinkNode(T d, CircLinkNode<T>* mlink = nullptr) :link(mlink), data(d) {}
	CircLinkNode(CircLinkNode<T>* mLink = nullptr) {}
};

template<class T>
class CircList:public LinearList<T>
{
public:
	CircList(const T& x):data(x);
	CircList(CircLinkNode<T> &mLink);
	~CircList();
	int Length()const;
	void MakeEmepty();
	bool IsEmpty{ return first->link == first ? true : false;}
	CircLinkNode<T> * GetHead() const{ return first; }

	SetHead(CircLinkNode<T>* head) { first = head; }
	CircLinkNode<T>* Seach(T x);
	CircLinkNode<T>* Locate(int i);
	T GetData(int i);
	void SetData(int i, T& d);
	bool Insert(int i, const T& x);
	bool Remove(int i, T&x);
private:
	CircLinkNode<T>* fist, *last;

}