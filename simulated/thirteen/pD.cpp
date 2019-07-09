#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

#define CITIES_MAX 20
#define DEST 1

static int pos[CITIES_MAX];
static int adj[CITIES_MAX][CITIES_MAX];
static int costs[CITIES_MAX][CITIES_MAX];
static int parent[CITIES_MAX];

static int amount_cities;

int minDistance(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 1; v <= amount_cities; v++)
     if (!visited[v] && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int dijkstra(int src, int dest)
{
	int u;
	int dist[amount_cities];
	bool visited[amount_cities];

	// printf("Path %d -> %d | %d\n", src, dest, amount_cities);

	for (int i = 0; i <= amount_cities; i++)
		dist[i] = INT_MAX, visited[i] = false;

	dist[src] = 0;

	for (int count = 0; count < amount_cities; count++)
	{
		int u = minDistance(dist, visited);

		// printf("Min: %d\n", u);

		if (u == dest || dist[u] == INT_MAX)
			break;

		visited[u] = true; 

		for (int i = 0; i < pos[u]; i++)
		{
			int v = adj[u][i];

			// printf(" Before %d: %d\n", v, dist[v]);

			if (!visited[v] && (dist[u] + costs[u][v]) < dist[v])
			{
				dist[v] = (dist[u] + costs[u][v]);
				// printf(" After V: %d\n", dist[v]);
				parent[v] = u;
			}
		}
	}

	return (dist[dest]);
}

int main()
{
	int c, e, u, v, p, src, total_time;

	while (true)
	{
		scanf("%d %d ", &c, &e);

		if (!c && !e)
			break;

		amount_cities = c;

		for (int i = 1; i <= c; ++i)
			pos[i] = 0;

		for (int i = 0; i < e; ++i)
		{
			scanf("%d %d %d ", &u, &v, &p);


			// printf("Edge: %d -> %d (%d)\n", u, v, p);

			adj[u][pos[u]++] = v;
			adj[v][pos[v]++] = u;

			costs[u][v] = p;
			costs[v][u] = p;
		}


		scanf("%d ", &src);

		total_time = dijkstra(src, DEST);
		int diff = (total_time - 120);

		if (diff <= 0)
			printf("Will not be late. Travel time - %d - best way - ", total_time);
		else if (diff == 1)
			printf("It will be 1 minute late. Travel time - %d - best way - ", total_time);
		else
			printf("It will be %d minutes late. Travel time - %d - best way - ", diff, total_time);

		string way("1");
		int curr = 1;
		while (curr != src)
		{
			curr = parent[curr];
			way = to_string(curr) + " " + way;
		}

		printf("%s\n", way.c_str());
	}

	return 0;
}