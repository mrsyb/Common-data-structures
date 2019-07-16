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

/*Dijkstra迪杰斯特拉算法<https://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html>
提法：给定一个有向带权图G与源点V0，各边上的权值均非负，要求找出从v到D中其余各顶点的最短路径
1.初始化：	S = {V0};								//S存放已求出 最短路径的终点
			Dist[j] = Edge[0][j],j = 0,1,2...,n-1;	//Dist[j]表示当前已经找出来的从源点V0到Vj的最短路径的权值，n为带权无向图顶点的个数
2.求出最短路径的长度：
			Dist[k] = min{Dist[i]},i属于V-S			//V表示带权无向图所有顶的集合
			S = S U {K};
3.修改：	Dist[i] = min{Dist[k] + Edge[k][i]},对于每一个i属于V - S;
4.判断：    若S = V ，则算法结束，否则转2；
*/

/*拓扑排序<https://blog.csdn.net/lisonglisonglisong/article/details/45543451>
定义：拓扑排序是一个有向无环图所有顶点的线性序列。
stack S;
检查所有顶点；
	if(顶点i的入度为0)
		顶点号i进栈S;
count = 0;
while(当栈S不空时)
{
	从栈S退出一个顶点v;
	输出v;
	count++;
	遍历顶点v的所有邻接顶点w,将其入度减一入度减至0的顶点w入栈S;
}
if(输出顶点个数count < 网络顶点个数n)
	报告网络中存在有向环；
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
	void Dijkstra(Graph<T, E>& G, T v, E dist[], int path[]);
protected:
	int MaxVertices;
	int NumEdgets;
	int NumVertices;
	virtual int GetVerticePos(T vertice);
	void DFS(Graph<T, E>& G, int v, bool Visited[], void(*Visit)(T));
};

