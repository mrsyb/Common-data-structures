#pragma once
#include "Graph.h"

template<class T,class E>
struct Edge
{
	int Dest;
	E Weight;
	Edge<T, E> *Link;
	Edge() {}
	Edge(int dest, E weight) :Dest(dest), Weight(weight), Link(NULL) {}
	bool operator !=(Edge<T, E>& R)const { return (Dest != R.Dest) ? true : false; }
};

template<class T,class E>
struct Vertex
{
	T Data;
	Edge<T, E>* Head;
	Vertex() :Head(NULL) {}
};

template<class T ,class E>
class Graphlnk:public Graph<T,E>
{
public:
	Graphlnk(int sz = DefaultVetices);
	~Graphlnk();

	virtual T GetValue(int i) override
	{
		return (i > 0 && i < this->NumVertices) ? NodeTable[i].Data : 0;
	}

	virtual E GetWeight(int v1, int v2) override;
	virtual int GetFirstNeighbor(int v) override;
	virtual int GetNextNeighbor(int v, int w) override;
	virtual bool InsertVertice(const T& vertice) override;
	virtual bool InsertEdge(int v1, int v2, E weight) override;
	virtual bool RemoveVertice(int v) override;
	virtual bool RemoveEdge(int v1, int v2) override;

protected:
	Vertex<T, E> *NodeTable;
	virtual int GetVerticePos(T vertice) override
	{
		for (int i = 0; i < this->NumVertices; i++)
		{
			if (NodeTable[i].Data == vertice)
				return i;
		}
		return -1;
	}

};

