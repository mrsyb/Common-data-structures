#pragma once
#include <iostream>
#include <cstdlib>
#include <assert.h>
template<class T>
struct GenListNode {
public:
	GenListNode()
	{
		Type = 0; 
		next = NULL; 
		Info->Ref = 0;
	}
	GenListNode(GenListNode<T>& other)
	{
		Type = other.Type;
		Info = other.Info;
		next = other.next;
	}

private:
	int Type;//0/1/2
	union 
	{
		int Ref;
		T Value;
		GenListNode<T>* child;
	}Info;
	GenListNode<T>* next;
};

template<class T>
struct Items {//返回值的类结构定义
	int Type;//0/1/2
	union
	{
		int Ref;
		T Value;
		GenListNode<T>* child;
	}Info;
	Items() //constructer
	{ 
		Type = 0;
		Info->Ref = 0; 
	}
	Items(Items<T>& other)//copy constructer
	{
		Type = other.Type;
		Info = other.Info;
	}
};

template<class T>
class GenList {
public:
	GenList();
	~GenList();
	bool Head(Items<T>& x);
	bool Tail(GenList<T>& x);
	GenListNode<T>* First();
	GenListNode<T>* Next(GenListNode<T>* Elem);
	void Copy(const GenList<T>& R);//递归拷贝外部调用
	int Length();
	int Depth();
	friend std::istream& operator>>(std::istream& in, GenList<T>& L);

private:
	GenListNode<T>* first;
	GenListNode<T>* Copy(GenListNode<T>* L);//递归拷贝内部调用,前提，非共享表或递归表
	int Length(GenListNode<T>* L);
	int Depth(GenListNode<T>* L);
	bool Equal(GenListNode<T>* s, GenListNode<T>* t);
	void Remove(GenListNode<T>* ls);//释放以L为表头的广义表，假定ls不为NULL
	void CreateList(std::istream& in, GenListNode<T> * &ls);
};

