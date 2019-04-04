#pragma once
#include "Graph.h"

template<class T,class E >
class Graphmtx :public Graph<T, E>
{

public:
	Graphmtx(int sz = DEfaultVetices);
	~Graphmtx() { delete[] VerticesList; delete[] Edge; }
	virtual T GetValue(int i) override
	{
		return i >= 0 && i <= this->NumVertices ? VerticesList[i] : NULL;
	}
	virtual E GetWeight(int v1, int v2) override
	{
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	virtual int GetFirstNeighbor(int v) override;
	virtual int GetNextNeighbor(int v, int w) override;
	virtual bool InsertVertice(const T& vertice) override;
	virtual bool InsertEdge(int v1, int v2, E weight) override;
	virtual bool RemoveVertice(int v) override;
	virtual bool RemoveEdge(int v1, int v2) override;

private:
	T *VerticesList;
	E ** Edge;
	virtual int GetVerticePos(T vertice) override
	{
		for (int i = 0;i<this->NumVertices;i++)
			if (VerticesList[i] == vertice) return i;
		return -1;
	}

};








