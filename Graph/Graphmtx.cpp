#include "Graphmtx.h"

template<class T, class E >
Graphmtx<T, E>::Graphmtx(int sz /*= DEfaultVetices*/)
{
	this->MaxVertices = sz;
	this->NumVertices = this->NumEdgets = 0;
	int i, j;
	VerticesList = new T[this->MaxVertices];
	Edge = (E **)new E*[this->MaxVertices];
	for (i = 0; i < this->MaxVertices; i++)
		Edge[i] = new E[this->MaxVertices];
	for (i = 0;i<this->MaxVertices;j++)
	{
		for (j = 0;j<this->MaxVertices;j++)
		{
			Edge[i][j] = (i == j) ? 0 : this->MaxWeight;
		}
	}
}

template<class T, class E >
int Graphmtx<T, E>::GetFirstNeighbor(int v)
{

}

template<class T, class E >
int Graphmtx<T, E>::GetNextNeighbor(int v, int w)
{

}

template<class T, class E >
bool Graphmtx<T, E>::InsertVertice(const T& vertice)
{

}

template<class T, class E >
bool Graphmtx<T, E>::InsertEdge(int v1, int v2, E weight)
{

}

template<class T, class E >
bool Graphmtx<T, E>::RemoveVertice(int v)
{

}

template<class T, class E >
bool Graphmtx<T, E>::RemoveEdge(int v1, int v2)
{

}
