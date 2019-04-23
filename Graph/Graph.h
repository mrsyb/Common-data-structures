#pragma once
/*Kruskal克鲁斯卡尔算法
T = 空集；                                                           //T是最小生成树的边集合，E是带权无向图的边集合
while（T包含的边数 < n-1 && E包含的边数 > 0）
{
	从E中选出一条权值weight最小的边（w,v）;
	从E中删除边（w,v）;
	if(将边（w,v）加入T后不会产生回路)
	{
		将边（w,v）加入T;
	}
}
if(T包含的变数 < n-1)
	生成失败；
*/

/*Prim普里姆算法
Vmst = {u0},Emst = 空集；                                            //Vmst为最小生成树的顶点集，Emst为最小生成树的边集，u0为最小生成树的出发顶点,
while(Vmust包含的顶点数小于n && E不为空)                             //E为带权无向图的边集
{
	从E中选出一条权值最小的边（w,v）&& w属于Vmust && v属于 V - Vmust;//V为带权无向图的顶点集
	将边（w,v）从E中删除；
	令Vmst = Vmst U {w},Emst = Emst U {(w,v)};
}
if(Vmst包含的顶点数小于n)
	生成失败；
*/

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
	int NumberOfVertices() { return NumVertices; }
	int MumberOfEdgets() { return NumEdgets; }
	virtual T GetValue(int i);
	virtual E GetWeight(int v1, int v2);
	virtual int GetFirstNeighbor(int v);
	virtual int GetNextNeighbor(int v, int w);
	virtual bool InsertVertice(const T& vertice);
	virtual bool InsertEdge(int v1, int v2, E weight);
	virtual bool RemoveVertice(int v);
	virtual bool RemoveEdge(int v1, int v2);
	void DFS(Graph<T, E>& G,const T& v, void(*Visit)(T));
	void BFS(Graph<T, E>& G, const T& v,void(*Visit)(T));
protected:
	int MaxVertices;
	int NumEdgets;
	int NumVertices;
	virtual int GetVerticePos(T vertice);
	void DFS(Graph<T, E>& G, int v, bool Visited[], void(*Visit)(T));
};

