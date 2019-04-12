#pragma once
#include <cstdlib>
const int DefaultVetices = 30;

template<class T ,class E>
class Graph
{
public:
	const E MaxWeight = ......;
	Graph(int SE = DefaultVetices);
	~Graph();
	bool GraphEmpty()const {
		return NumEdgets == 0 ? true : false;
	}
	bool GraphFull() {
		if (NumVertices == MaxVertices || NumEdgets == MaxVertices * (MaxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NunberOfVertices() { return NumVertices; }
	int MumberOfEdgets() { return NumEdgets; }
	virtual T GetValue(int i);
	virtual E GetWeight(int v1, int v2);
	virtual int GetFirstNeighbor(int v);
	virtual int GetNextNeighbor(int v, int w);
	virtual bool InsertVertice(const T& vertice);
	virtual bool InsertEdge(int v1, int v2, E weight);
	virtual bool RemoveVertice(int v);
	virtual bool RemoveEdge(int v1, int v2);
protected:
	int MaxVertices;
	int NumEdgets;
	int NumVertices;
	virtual int GetVerticePos(T vertice);
};

