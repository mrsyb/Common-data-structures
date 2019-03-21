#include "GenList.h"

template<class T>
GenList<T>::GenList()
{
	first = new GenListNode<T>;
	assert(first);
}

template<class T>
GenList<T>::~GenList()
{
	Remove(first);
}

template<class T>
bool GenList<T>::Head(Items<T>& x)
{
	if (first->next == NULL)return false;//表空
	else
	{
		x.Type = first->Type;
		x.Info = first->Info;
		return true;
	}
}

template<class T>
bool GenList<T>::Tail(GenList<T>& x)
{
	if (first->next == NULL) return false;
	else {
		x.first->Type = 0;
		x.first->Info.Ref = 0;
		x.first->next = Copy(first->next->next);
		return true;
	}
}

template<class T>
GenListNode<T>* GenList<T>::First()
{
	if (first->next == NULL)return NULL;
	else {
		return first->next;
	}
}

template<class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T>* Elem)
{
	if (Elem->next == NULL)return NULL;
	else {
		return Elem->next;
	}
}

template<class T>
void GenList<T>::Copy(const GenList<T>& R)
{
	first->Copy(R->first);
}

template<class T>
int GenList<T>::Length()
{
	return Length(first);
}

template<class T>
int GenList<T>::Depth()
{
	return Depth(first);
}

template<class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T>* L)
{
	GenListNode<T>* q = NULL;
	if (L != NULL)
	{
		q = new GenListNode<T>;
		q->Type = L->Type;
		switch (L->Type)
		{
		case 0:
			q->Info->Ref = L->Info->Ref;
			break;
		case 1:
			q->Info->Value = L->Info->Value;
			break;
		case 2:
			q->Info->child = L->Info->child;
			break;
		}
		q->next = Copy(L->next);
	}
	return q;
}

template<class T>
int GenList<T>::Length(GenListNode<T>* L)
{
	if (L != NULL) return 1 + Length(L->next);
	else return 0;
}

template<class T>
int GenList<T>::Depth(GenListNode<T>* L)
{
	if (L == NULL) return 1;
	GenListNode<T> temp = L->next;
	int m = 0, n;
	while (L!= NULL)
	{
		if (L->Type == 2)
		{
			n = Depth(L->Info->child);
		}
		if (n > m)
			m = n;
		L = L->next;
	}
	return m + 1;
}

template<class T>
void GenList<T>::Remove(GenListNode<T>* ls)
{
	ls->Info.Ref--;
	if (ls->Info.Ref <= 0)
	{
		GenListNode<T>* q;
		while (ls->next != NULL)
		{
			q = ls->next;
			if (q->Type == 2)//若是子表头节点，递归删除（引用计数减一，尝试删除）
			{
				Remove(q->Info->child);
				if (q->Info.child->Info.Ref <= 0)
					delete q->Info.child;
			}
			//原子结点，直接删除即可
			ls->next = q->next;
			delete q;
		}
	}
}

template<class T>
bool GenList<T>::Equal(GenListNode<T>* s, GenListNode<T>* t)
{
	int x;
	if (s->next == NULL && t->next == NULL)return true;
	if (s->next != NULL && t->next != NULL && s->Type == t->Type)
	{
		if (s->Type == 1)
			x = s->Info->Value == t->Info->Value?1:0;
		if (s->Type == 2)
			x = Equal(s->Info->child, t->Info->child);
		if (x == 1) return Equal(s->next, t->next);
	}
	return false;
}

template<class T>
void GenList<T>::CreateList(std::istream& in, GenListNode<T> * &ls)
{

}
