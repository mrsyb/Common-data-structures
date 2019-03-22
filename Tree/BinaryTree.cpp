#include"BinaryTree.h"


template <class T>
int BinaryTree<T>::Hight(BinaryNode<T>* root)
{
	int n, m;
	if (root == NULL)return 0;
	else
	{
		n = Hight(root->Left);
		m = Hight(root->Right);
	}
	return n > m ? n + 1: m + 1;

}

template<class T>
int BinaryTree<T>::Size(BinaryNode<T>* root)
{
	if (root == NULL)return 0;
	else 
		return 1 + Size(root->Left) + Size(root->Right);
}

template<class T>
BinaryNode<T>* BinaryTree<T>::Parent(BinaryNode<T>* SubTree, BinaryNode<T>* Current)
{
	BinaryNode<T>* p;
	if (SubTree == NULL)
	{
		return NULL;
	}
	
	if (SubTree->Left == Current || SubTree->Right == Current)
	{
		return SubTree;
	}
	if (SubTree->Left != NULL)
	{
		return Parent(SubTree->Left, Current);
	}
	else if(SubTree->Right != NULL)
	{
		return Parent(SubTree->Right, Current);
	}
}

template<class T>
void BinaryTree<T>::Destory(BinaryNode<T>* root)
{
	if (root->Left == NULL && root->Right == NULL)
		delete root;
	else if(root->Left != NULL){
		Destory(root->Left);
	}
	else if(root->Right != NULL){
		Destory(root->Right);
	}
}


template<class T>
int BinaryTree<T>::Insert(const T & Item)
{
	return 0;
}

template<class T>
BinaryNode<T>* BinaryTree<T>::Find(const T & Item) const
{
	return NULL;
}


template <class T>
void BinaryTree<T>::LevelOrder(BinaryNode<T>* root, void(*Visit)(BinaryNode<T>* Current))
{
	Queue<BinaryNode<T>*> Q;
	BinaryNode<T>* p = root;
	Q.EnQueue(p);
	while (!Q.IsEmpty())
	{
		Q.Dequeue(p);
		Visit(p);
		if (p->Left != NULL)
		{
			Q.EnQueue(p->Left);
		}
		if (p->Right != NULL)
		{
			Q.EnQueue(p->Right);
		}
	}
}



template<class T>
void BinaryTree<T>::RecursionPreOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	if (SubTree!= NULL)
	{
		Visit(SubTree);
		RecursionPreOrder(SubTree->Left);
		RecursionPreOrder(SubTree->Right);
	}
}

template<class T>
void BinaryTree<T>::RecursionInOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	if (SubTree != NULL)
	{
		RecursionInOrder(SubTree->Left);
		Visit(SubTree);
		RecursionInOrder(SubTree->Right);
	}
}

template<class T>
void BinaryTree<T>::RecursionPostOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	if (SubTree != NULL)
	{
		RecursionPostOrder(SubTree->Left);
		RecursionPostOrder(SubTree->Right);
		Visit(SubTree);
	}
}

template<class T>
void BinaryTree<T>::NoRecuPreOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	LinkedStack<BinaryNode<T>*> S;
	BinaryNode<T>* p = SubTree;
	
	while (p!= NULL||!S->IsEmpty())
	{
		while (p != NULL)
		{
			Visit(p);
			S->Push(p);
			p = p->Left;
		}
		if (!S->IsEmpty())
		{
			S->Pop(p);
			p = p->Right;
		}
	}
}

template<class T>
void BinaryTree<T>::NoRecuInOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	LinkedStack<BinaryNode<T>*> S;
	BinaryNode<T>* p = SubTree;

	while (p!=NULL||!S->IsEmpty())
	{
		while (p!= NULL)
		{
			S->Push(p);
			p = p->Left;
		}
		if (!S->IsEmpty())
		{
			S->Pop(p);
			Visit(p);
			p = p->Right;
		}

	}
}

template<class T>
void BinaryTree<T>::NoRecuPostOrder(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	LinkedStack<pair<BinaryNode<T> *, bool>> S;
	pair<BinaryNode<T>*, bool> TempPair;
	BinaryNode<T>* p = SubTree;

	while (p != NULL || !S->IsEmpty())
	{
		while (p != NULL)
		{
			TempPair = make_pair(p, true);//true表示第一次入栈
			S->Push(TempPair);
			p = p->Left;
		}
		if (!S->IsEmpty())
		{
			S->Pop(TempPair);
			if (TempPair->second == true)
			{
				TempPair = make_pair(p, false);
				S->Push(TempPair);
				p = p->Right;
			}
			else
			{
				p = TempPair->first;
				Visit(p);
				p = NULL;
			}
		}
	}
}
template <class T>
void BinaryTree<T>::NoRecuPreOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current))
{
	LinkedStack< pair<BinaryNode<T>*, bool> > s;
	BinaryNode<T>* p = SubTree;

	s.Push(make_pair(p, false));
	bool visited;
	while (!s.IsEmpty())
	{
		p = s.GetTop().first;
		visited = s.GetTop().second;
		s.Pop();
		if (p == NULL)
			continue;
		if (visited)
		{
			Visit(p);
		}
		else
		{
			s.Push(make_pair(p, true));
			s.Push(make_pair(p->right, false));
			s.Push(make_pair(p->left, false));
		}
	}
}

template <class T>
void BinaryTree<T>::NoRecuInOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>* Current))
{
	LinkedStack< pair<BinaryNode<T>*, bool> > s;
	BinaryNode<T>* p = SubTree;

	s.Push(make_pair(p, false));
	bool visited;
	while (!s.IsEmpty())
	{
		p = s.GetTop().first;
		visited = s.GetTop().second;
		s.Pop();
		if (p == NULL)
			continue;
		if (visited)
		{
			Visit(p);
		}
		else
		{
			s.Push(make_pair(p->right, false));
			s.Push(make_pair(p, true));
			s.Push(make_pair(p->left, false));
		}
	}
}

template<class T>
inline void BinaryTree<T>::NoRecuPostOrder2(BinaryNode<T>* SubTree, void(*Visit)(BinaryNode<T>*Current))
{
	LinkedStack< pair<BinaryNode<T>*, bool> > s;
	BinaryNode<T>* p = SubTree;

	s.Push(make_pair(p, false));
	bool visited;
	while (!s.IsEmpty())
	{
		p = s.GetTop().first;
		visited = s.GetTop().second;
		s.Pop();
		if (p == NULL)
			continue;
		if (visited)
		{
			Visit(p);
		}
		else
		{
			s.Push(make_pair(p->right, false));
			s.Push(make_pair(p->left, false));
			s.Push(make_pair(p, true));
		}
	}
}


