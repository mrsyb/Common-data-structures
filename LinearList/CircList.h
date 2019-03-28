#pragma once
#include "LinearList.h"
#include <cstdlib>

template <class T>
struct CircLinkNode {
	T data;
	CircLinkNode<T>* link;
	CircLinkNode(T d, CircLinkNode<T>* mlink = nullptr) :link(mlink), data(d) {}
	CircLinkNode(CircLinkNode<T>* mLink = nullptr) {}
};

template<class T>
class CircList
{
public:
	CircList(CircLinkNode<T> first = NULL, CircLinkNode<T> last = NULL) :first(first), last(last) {}
	CircList(CircLinkNode<T> &mLink);
	~CircList() { MakeEmepty(); };
	int Length()const;
	void MakeEmepty();
	CircLinkNode<T>* Seach(T x);
	CircLinkNode<T>* Locate(int i);
	T GetData(int i);
	void SetData(int i, T & d);
	bool Insert(int i, const T & x);
	bool Remove(int i, T & x);
	bool IsEmpty{ return first->link == first ? true : false; }
	CircLinkNode<T> * GetHead() const { return first; }
	SetHead(CircLinkNode<T>* head) { first = head; }
private:
	CircLinkNode<T>* first;
	CircLinkNode<T>* last;
};