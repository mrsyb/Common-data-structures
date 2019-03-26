#include "ThreadTree.h"

template<class T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T>* Current)
{
	ThreadNode<T> *p = Current;
	while (p->LTag == 0)
	{
		p = p->LeftChild;
	}
	return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T>* Current)
{
	ThreadNode<T> *p = Current;
	while (p->RTag == 0)
	{
		p = p->RightChild;
	}
	return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Piror(ThreadNode<T>* Current)
{
	ThreadNode<T> *p = Current->LeftChild;
	if (p->LTag == 0) return Last(p);
	else return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T>* Current)
{
	ThreadNode<T>* p = Current->RightChild;
	if (p->RTag == 0) return First(p);
	else return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Parent(ThreadNode<T>* t)
{
	ThreadNode<T> *p;
	if (t == Root)return NULL;
	for (p = t; p->LTag == 0; p = p->LeftChild);
	if (p->LeftChild != NULL)
		for (p = p->LeftChild; p != NULL && p->LeftChild != t && p->RightChild != t; p = p->RightChild);
	if (p == NULL || p->LeftChild == NULL) {
		for (p = t; p->RTag == 0; p = p->RightChild);
		for (p = p->RightChild; p != NULL && p->LeftChild != t && p->RightChild != t; p = p->LeftChild);
	}
	return p;
}

template<class T>
ThreadTree<T>* ThreadTree<T>::CreatInThread()
{
	ThreadNode<T>* Pre = NULL;
	if (Root != NULL)
	{
		CreatInThread(Root, Pre);
		Pre->RightChild = NULL;
		Pre->RTag = 1;
	}
	return nullptr;
}

template<class T>
void ThreadTree<T>::CreatInThread(ThreadNode<T>* Current, ThreadNode<T>* Pre)
{
	if (Current == NULL) return;
	CreatInThread(Current->LeftChild, Pre);
	if (Current->LeftChild == NULL)
	{
		Current->LeftChild = Pre;
		Current->LTag = 1;
	}
	if (Pre != NULL && Pre->RightChild == NULL)
	{
		Pre->RightChild = Current;
		Pre->RTag = 1;
	}
	Pre = Current;
	CreatInThread(Current->RightChild, Pre);
}

template<class T>
void ThreadTree<T>::PreOrder(void(*Visit)(ThreadNode<T>*))
{
	ThreadNode<T>* p = Root;
	while (p != NULL)
	{
		Visit(p);
		if (p->LTag == 0)
			p = p->LeftChild;
		else if (p->RTag == 0)
			p = p->RightChild;
		else
		{
			while (p != NULL&& p->RTag ==1)
			{
				p = p->RightChild;
			}
			if (p != NULL)
				p = p->RightChild;
		}
	}
}


template<class T>
void ThreadTree<T>::PostOrder(void(*Visit)(ThreadNode<T>*))
{
	ThreadNode<T>* t = Root;
	while (t->LTag == 0||t->RTag == 0)
	{
		if (t->LTag == 0)
		{
			t = t->LeftChild;
		}
		else if(t->RTag == 0)
		{
			t = t->RightChild;
		}
	}
	Visit(t);
	ThreadNode<T>* p;
	while (p->parent(t) != NULL)
	{
		if (p->RightChild == t || p->RTag == 1)
		{
			t = p;
		}
		else
		{
			t = p->RightChild;
			while (t->LTag == 0|| t->RTag == 0)
			{
				if (t->LTag == 0)
				{
					t = t->LeftChild;
				}
				else if (t->RTag == 0)
				{
					t = t->RightChild;
				}
			}
		}
		Visit(t);
	}
}


template<class T>
void ThreadTree<T>::InOrder(void(*Visit)(ThreadNode<T>*))
{
	ThreadNode<T>* p;
	for (p = First(Root); p != NULL; p = Next(p))
		Visit(p);
}

