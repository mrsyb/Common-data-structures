#include "Graphlnk.h"

template<class T, class E>
Graphlnk<T, E>::Graphlnk(int sz)
{
	this->MaxVertices = sz;
	this->NumEdgets = this->NumVertices = 0;
	NodeTable = new Vertex<T, E>[this->MaxVertices];
	assert(NodeTable);
}

template<class T, class E>
Graphlnk<T, E>::~Graphlnk()
{
	for (int i = 0; i < this->MaxVertices; i++)
	{
		Edge<T, E>* temp = NodeTable[i].Head;
		while (temp != NULL)
		{
			NodeTable->Head = NodeTable->Head->Link;
			delete temp;
			temp = NodeTable->Head;
		}
	}
	delete[] NodeTable;
}

template<class T, class E>
E Graphlnk<T, E>::GetWeight(int v1, int v2)
{
	if (v1 < 0 && v1 >= this->MaxVertices && v2 < 0 && v2 >= this->MaxVertices) return NULL;
	Edge<T,E>* temp = NodeTable[v1].Head;
	while (temp != NULL)
	{
		if (temp->Dest == v2)
		{
			return temp->Weight;
		}
		temp = temp->Link;
	}
}

template<class T, class E>
int Graphlnk<T, E>::GetFirstNeighbor(int v)
{
	if (v > this->MaxVertices || v < 0)
		return -1;
	return (NodeTable[v].Head != NULL)?NodeTable[v].Head->Dest:-1;
}

template<class T, class E>
int Graphlnk<T, E>::GetNextNeighbor(int v, int w)
{
	if (v > this->MaxVertices || v < 0)
		return -1;
	Edge<T, E>* temp = NodeTable[v].Head;
	while (temp != NULL)
	{
		if (temp->Dest == w)
			return (temp->Link != NULL) ? temp->Link->Dest : -1;
	}
}

template<class T, class E>
bool Graphlnk<T, E>::InsertVertice(const T & vertice)
{
	if (this->NumVertices == this->MaxVertices)return false;
	NodeTable[this->NumVertices++].Data = vertice;
	return true;
}

template<class T, class E>
bool Graphlnk<T, E>::InsertEdge(int v1, int v2, E weight)
{
	if (v1<0 || v1>this->NumVertices || v2<0 || v2>this->NumVertices) return false;

	Edge<T, E>* temp1 = NodeTable[v1].Head;
	Edge<T, E>* temp2 = NodeTable[v2].Head;

	if (temp1 == NULL)
		temp1 = new Edge<T, E>(v2, weight);
	else
	{
		while (temp1->Link != NULL)
		{
			if (temp1->Dest == v2)
			{
				temp1->Weight = weight;
				break;
			}
			temp1 = temp1->Link;
		}
		if (temp1->Link == NULL)
		{
			temp1 ->Link = new Edge<T, E>(v2, weight);
		}
	}

	if (temp2 == NULL)
	{
		temp2 = new Edge<T, E>(v2, weight);
		this->NumEdgets++;
		return true;
	}
	else
	{
		while (temp2->Link != NULL)
		{
			if (temp2->Dest == v2)
			{
				temp2->Weight = weight;
				this->NumEdgets++;
				return true;
			}
			temp2 = temp2->Link;
		}
		if (temp2->Link == NULL)
		{
			temp2->Link = new Edge<T, E>(v2, weight);
			this->NumEdgets++;
			return true;
		}
	}
}

template<class T, class E>
bool Graphlnk<T, E>::RemoveVertice(int v)
{
	if(this->NumVertices == 1 || v < 0 || v >= this->NumVertices)
	return false;

	Edge<T, E>* p, *s, *t;
	int i, k;

	while (NodeTable[v].Head != NULL)
	{
		p = NodeTable[v].Head; k = p->Dest;
		s = NodeTable[k].Head; t = NULL;

		while (s != NULL && s->Dest != v)
		{
			t = s; 
			s = s->Link;
		}

		if (s != NULL)
		{
			if (t == NULL)
				NodeTable[k].Head = s->Link;
			else
				t->Link = s->Link;
			delete s;
		}
		NodeTable[v].Head = p->Link;
		delete p;
		this->NumEdgets--;
	}

	this->NumVertices--;
	NodeTable[v].Data = NodeTable[this->NumVertices].Data;
	p = NodeTable[v].Head = NodeTable[this->NumVertices].Head;
	while (p != NULL)
	{
		s = NodeTable[p->Dest];
		while (s != NULL)
		{
			if (s->Dest == this->NumVertices)
			{
				s->Dest = v;
				break;
			}
			else
			{
				s = s->Link;
			}
		}
	}
	return true;
}

template<class T, class E>
bool Graphlnk<T, E>::RemoveEdge(int v1, int v2)
{
	return false;
}
