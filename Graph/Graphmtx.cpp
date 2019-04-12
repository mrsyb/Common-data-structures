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
	if (v != -1)
	{
		for (int col = 0;col<this->NumVertices;col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < this->MaxWeight)
				return col;
		}
	}
	return -1;
}

template<class T, class E >
int Graphmtx<T, E>::GetNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < this->NumVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < this->MaxWeight)
				return col;
	}
	return -1;
}

template<class T, class E >
bool Graphmtx<T, E>::InsertVertice(const T& vertice)
{
	if (this->NumVertices == this->MaxVertices)return false;
	VerticesList[this->NumVertices++] = vertice;
	return true;
}

template<class T, class E >
bool Graphmtx<T, E>::InsertEdge(int v1, int v2, E weight)
{
	if (v1<0 || v1>this->MaxVertices || v2<0 || v2>this->MaxVertices || weight > this->MaxWeight || weight < 1 || Edge[v1][v2] != this->MaxWeight || Edge[v2][v1] != this->MaxWeight)
		return false;
	Edge[v1][v2] = Edge[v2][v1] = weight;
	this->NumEdgets++;
	return true;
}

template<class T, class E >
bool Graphmtx<T, E>::RemoveVertice(int v)
{
	if (v<0 || v>= this->NumVertices)return false;
	if (this->NumVertices == 1) false;
	int i, j;
	VerticesList[v] = VerticesList[this->NumVertices - 1];
	for (i = 0; i < this->NumVertices; i++)
		if (Edge[i][v] > 0 && Edge[i][v] < this->MaxWeight)this->NumEdgets--;
	for (i = 0; i < this->NumVertices; i++)
		Edge[i][v] = Edge[i][this->NumVertices - 1];
	for (j = 0; j < this->NumVertices; j++)
		Edge[v][j] = Edge[this->NumVertices - 1][j];
	//重置最后一行一列
	for (i = 0;i< this->NumVertices;i++)
	{
		Edge[i][this->NumVertices-1] = this->MaxWeight;
		Edge[this->NumVertices-1][i] = this->MaxWeight;
	}
	Edge[this->NumVertices-1][this->NumVertices-1] = 0;

	this->NumVertices--;
	return true;
}

template<class T, class E >
bool Graphmtx<T, E>::RemoveEdge(int v1, int v2)
{
	if (v1 > 0 && v1 < this->NumEdgets && v2 > -1 && v2 < this->NumEdgets&&Edge[v1][v2]>0 && Edge[v1][v2] < this->MaxWeight)
	{ 
		Edge[v1][v2] = Edge[v2][v1] = this->MaxWeight;
		this->NumEdgets--;
		return true;
	}
	else return false;
}
