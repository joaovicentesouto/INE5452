#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <cmath>

using namespace std;

#define ERROR (1e-9)
#define MAX_ANTENNAS (101)

struct Coord
{
	int x, y, r;
} antennas[MAX_ANTENNAS];

//! Graph variables
int amount_antennas;
int adj[MAX_ANTENNAS][MAX_ANTENNAS];
int pos[MAX_ANTENNAS];
double ws[MAX_ANTENNAS][MAX_ANTENNAS];

//! Dijkstra variables
double distances[MAX_ANTENNAS];
bool visited[MAX_ANTENNAS];

static inline double euclidean_distance(int a, int b)
{
	return sqrt(
		  pow(antennas[a].x - antennas[b].x, 2)
		+ pow(antennas[a].y - antennas[b].y, 2)
	);
}

static inline void connect(int a, int b, double w)
{
	adj[a][pos[a]++] = b;
	ws[a][b] = w;

	// printf("connect %d to %d with %f\n", a, b, w);
}

static inline int minimum_distance()
{
	double min_index;
	double min = DBL_MAX;

	for (int v = 1; v <= amount_antennas; v++)
		if (!visited[v] && distances[v] <= min)
			min = distances[v], min_index = v;

	return min_index;
}

bool dijkstra(int src, int dest)
{
	for (int i = 1; i <= amount_antennas; i++)
		distances[i] = DBL_MAX, visited[i] = false;

	distances[src] = 0;

	// printf("Search %d to %d\n", src, dest);

	for (int count = 0; count < amount_antennas; count++)
	{
		int u = minimum_distance();

		// printf("Get u: %d\n", u);

		bool unreacheable = (DBL_MAX - distances[u]) < ERROR;

		if (u == dest || unreacheable)
			return !unreacheable;

		visited[u] = true;

		for (int i = 0; i < pos[u]; i++)
		{
			int v = adj[u][i];

			if (!visited[v] && ((distances[u] + ws[u][v]) - distances[v] < ERROR))
				distances[v] = distances[u] + ws[u][v];
		}
	}

	return false;
}

int main()
{
	int c, u, v, distance;

	while (true)
	{
		scanf("%d ", &amount_antennas);

		if (!amount_antennas)
			break;

		for (int i = 1; i <= amount_antennas; i++)
		{
			scanf("%d %d %d ", &antennas[i].x, &antennas[i].y, &antennas[i].r);
			
			pos[i] = 0;

			for (int j = 1; j < i; j++)
			{
				distance = euclidean_distance(j, i);

				if ((antennas[i].r - distance) > ERROR)
					connect(i, j, distance);

				if ((antennas[j].r - distance) > ERROR)
					connect(j, i, distance);
			}
		}

		scanf("%d ", &c);

		for (int i = 1; i <= c; i++)
		{
			scanf("%d %d ", &u, &v);

			if (dijkstra(u, v))
				printf("%d\n", (int) distances[v]);
			else
				printf("-1\n");
		}
	}

	return 0;
}
