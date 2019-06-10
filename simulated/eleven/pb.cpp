#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
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

void dijkstra(Graph & g, int src, int max_dist, set<int> &visiteds)
{
	int dist[g.n];
	bool sptSet[g.n];

	for (int i = 1; i < g.n; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	bool updated = false;
	for (int count = 1; count < g.n; count++)
	{
		updated = false;
		int u = minDistance(g.n, dist, sptSet);

		sptSet[u] = true;

		if (dist[u] <= max_dist && u != src)
			visiteds.insert(u);

		for (int v = 1; v < g.n; v++)
			if (!sptSet[v]
				&& dist[u] != INT_MAX
				&& (dist[u] + 1) < dist[v]
				&& (dist[u] + 1) <= max_dist
				&& contains(g.adj[u], v)
			)
			{
				dist[v] = (dist[u] + 1);
				updated = true;
			}
	}
}

int main()
{
	int test = 1;
	int c, e, l, p;

	while (cin >> c >> e >> l >> p)
	{
		Graph g;
		int u, v;

		if ((c + e + l + p) == 0)
			break;

		g.n = c+1;

		for (int i = 0; i < e; ++i)
		{
			cin >> u >> v;

			g.adj[u].insert(v);
			g.adj[v].insert(u);
		}

		set<int> visiteds;
		dijkstra(g, l, p, visiteds);

		cout << "Teste " << test++ << endl;
		for (int vis : visiteds)
			cout << vis << " ";
		cout << endl << endl;
	}

	return 0;
}