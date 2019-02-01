#pragma once
#include "LinearList.h"

template<class T>
struct LinkedNode
{
	T data;
	LinkedNode<T> *link;
	LinkedNode(LinkedNode<T> *ptr = nullptr):link(ptr) {};
	LinkedNode(const T& item, LinkedNode<T> *ptr = nullptr):data(item),link(ptr){}
};


template  <class T>
class List :public LinearList<T>
{
public:
	List() { first = new LinkedNode<T>(); std::cout << "¹¹Ôì"; }
	List(List<T> &L);
	~List() { clear(); }

	int Size() const override { return Length(); }
	int Length() const override;
	bool GetData(int i, T& x) override;
	LinkedNode<T>* MySearch(const T& x)const;
	LinkedNode<T>* GetHead()const { return first; }
	LinkedNode<T>* Locate(int i);
	void SetData(int i, const T& x) override;
	bool Remove(int i, T&x) override;
	bool Insert(int i, const T& x) override;
	bool IsEmpty() override;
	void Output() override;
	void clear();
	void InputFront(T endFlag);
	void InputRear(T endFlag);
	List<T>& operator=(List<T>& L);

private:
	LinkedNode<T>* first;

};

