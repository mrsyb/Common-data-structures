#include "Graph.h"
#include "../Queue/Queue.h"


template<class T, class E>
void Graph<T, E>::DFS(Graph<T, E>& G, const T & v,void(*Visit)(T))
{
	int i, loc, n = G.NumberOfVertices();
	bool *Visited = new bool[n];
	for (i = 0; i < n; i++) Visited[i] = false;
	loc = G.GetVerticePos(v);
	DFS(G, v, Visited,Visit);
	delete[] Visited;
}

template<class T, class E>
void Graph<T, E>::BFS(Graph<T, E>& G, const T & v,void(*Visit)(T))
{
	int i, w, n = G.NumberOfVertices();
	bool Visited = new bool[n];
	for (int i = 0; i < n; i++) Visited[i] = false;
	int loc = G.GetVerticePos(v);
	Visited(G.GetValue(v));
	Visited[loc] = true;
	Queue<int> Q;
	Q.EnQueue(loc);
	while (Q.IsEmpty())
	{
		Q.Dequeue(loc);
		w = G.GetFirstNeighbor(loc);
		while (w != -1)
		{
			if (Visited[w] == false)
			{
				Visit(G.GetValue(w));
				Visited[w] = true;
				Q.EnQueue(w);
			}
			w = G.GetNextNeighbor(loc, w);
		}
	}
	delete[] Visited;
}


template<class T, class E>
void Graph<T, E>::DFS(Graph<T, E>& G, int v, bool Visited[], void(*Visit)(T))
{
	Visit(G.GetValue());
	Visited[v] = true;
	int w = G.GetFirstNeighbor(v);
	while (w != -1)
	{
		if (Visited[w] == false) {
			DFS(G, w, Visited, Visit);
		}
		w = G.GetNextNeighbor(v,w);
	}
}
