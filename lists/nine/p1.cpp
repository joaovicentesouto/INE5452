#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

#define CITIES_MAX 251

static int pos[CITIES_MAX];
static int adj[CITIES_MAX][CITIES_MAX];
static int costs[CITIES_MAX][CITIES_MAX];

static int amount_cities;

int minDistance(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < amount_cities; v++)
     if (!visited[v] && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int dijkstra(int src, int dest)
{
	int u;
	int dist[amount_cities];
	bool visited[amount_cities];

	for (int i = 0; i < amount_cities; i++)
		dist[i] = INT_MAX, visited[i] = false;

	dist[src] = 0;

	for (int count = 0; count < amount_cities; count++)
	{
		u = minDistance(dist, visited);

		if (u == dest || dist[u] == INT_MAX)
			break;

		visited[u] = true;

		if (u < dest)
		{

			if (!visited[u + 1] && (dist[u] + costs[u][u + 1]) < dist[u + 1])
				dist[u + 1] = (dist[u] + costs[u][u + 1]);
		}
		else
		{
			for (int i = 0; i < pos[u]; i++)
			{
				int v = adj[u][i];

				if (!visited[v] && (dist[u] + costs[u][v]) < dist[v])
					dist[v] = (dist[u] + costs[u][v]);
			}
		}
	}

	while (u < dest)
	{
		dist[u + 1] = dist[u] + costs[u][u + 1];
		u++;
	}

	return (dist[dest]);
}

int main()
{
	int n, m, src, u, v, p, total_costs, dest;

	while (true)
	{
		scanf("%d %d %d %d ", &n, &m, &dest, &src);

		if ((n + m + dest + src) == 0)
			break;

		amount_cities = n;
		dest--;

		for (int i = 0; i < n; ++i)
			pos[i] = 0;

		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d ", &u, &v, &p);

			adj[u][pos[u]++] = v;
			adj[v][pos[v]++] = u;

			costs[u][v] = p;
			costs[v][u] = p;
		}

		total_costs = dijkstra(src, dest);

		printf("%d\n", total_costs);
	}

	return 0;
}