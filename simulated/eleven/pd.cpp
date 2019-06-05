#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <limits.h> 

using namespace std;

struct Graph
{
	int n{1};
	unordered_map<string, int> names;
	unordered_map<int, unordered_set<int>> adj;
	unordered_map<int, bool> visited;
};

int minDistance(int n, int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 1; v < n; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
}

bool contains(unordered_set<int> & set, int v)
{
	return set.find(v) != set.end();
}

int dijkstra(Graph & g, int src, int dest)
{
	int dist[g.n];
	bool sptSet[g.n];

	for (int i = 1; i < g.n; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0;

	for (int count = 1; count < g.n; count++)
	{
		int u = minDistance(g.n, dist, sptSet);

		if (u == dest)
			break;

		sptSet[u] = true; 

		for (int v = 1; v < g.n; v++)
			if (!sptSet[v] && dist[u] != INT_MAX && (dist[u] + 1) < dist[v] && contains(g.adj[u], v))
				dist[v] = (dist[u] + 1);
	}

     return (dist[dest]);
}

int main()
{
	int n, m;

	while (cin >> n >> m)
	{
		Graph g;
		int pontos, ligacoes, u, v;

		g.n = n+1;

		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v;

			g.adj[u].insert(v);
			g.adj[v].insert(u);
		}

		int c, r, e;

		cin >> c >> r >> e;

		for (int v : g.adj[e])
			g.adj[v].erase(e);

		int count = dijkstra(g, c, r);

		cout << count << endl;
	}

	return 0;
}