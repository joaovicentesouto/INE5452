#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <cmath>

using namespace std;

#define ERROR (1e-9)
#define MAX_CITIES (501)

struct Coord
{
	int x, y, r;
} cities[MAX_CITIES];

//! Graph variables
int amount_cities;
int adj[MAX_CITIES][MAX_CITIES];
int pos[MAX_CITIES];
int hours[MAX_CITIES][MAX_CITIES];

//! Dijkstra variables
int distances[MAX_CITIES];
bool visited[MAX_CITIES];

static inline void connect(int a, int b, int h)
{
    int j;
    int i = pos[a]++;
    bool same_country = false;

	adj[a][i] = b;

    for (j = 0; j < pos[b]; ++j)
        if (adj[b][j] == a)
        {
            same_country = true;
            break;
        }

    if (same_country)
    {
        hours[a][b] = 0;
        hours[b][a] = 0;
    }
    else
        hours[a][b] = h;

	// printf("connect %d to %d with %d\n", a, b, hours[a][b]);
}

static inline int minimum_distance()
{
	int min_index;
	int min = INT_MAX;

	for (int v = 1; v <= amount_cities; v++)
		if (!visited[v] && distances[v] <= min)
			min = distances[v], min_index = v;

	return min_index;
}

void dijkstra(int src, int dest)
{
	for (int i = 1; i <= amount_cities; i++)
		distances[i] = INT_MAX, visited[i] = false;

	distances[src] = 0;

	// printf("Search %d to %d\n", src, dest);

	for (int count = 0; count < amount_cities; count++)
	{
		int u = minimum_distance();

		// printf("Get u: %d\n", u);

		if (u == dest || (distances[u] == INT_MAX))
			return;

		visited[u] = true;

		for (int i = 0; i < pos[u]; i++)
		{
			int v = adj[u][i];

			if (!visited[v] && ((distances[u] + hours[u][v]) - distances[v] < ERROR))
				distances[v] = distances[u] + hours[u][v];
		}
	}
}

int main()
{
	int edges, u, v, h, queries;

	while (true)
	{
		scanf("%d %d", &amount_cities, &edges);

		if (!amount_cities && !edges)
			break;
        
        for (int i = 1; i <= amount_cities; i++)
            pos[i] = 0;

		for (int i = 0; i < edges; i++)
		{
			scanf("%d %d %d ", &u, &v, &h);

            connect(u, v, h);
		}

		scanf("%d ", &queries);

		for (int i = 0; i < queries; i++)
		{
			scanf("%d %d ", &u, &v);

			dijkstra(u, v);

            if (distances[v] != INT_MAX)
				printf("%d\n", distances[v]);
			else
				printf("Nao e possivel entregar a carta\n");
		}

        printf("\n");
	}

	return 0;
}
