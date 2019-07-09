#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define DIGMON_MAX 1001

static int pos[DIGMON_MAX];
static int adj[DIGMON_MAX][DIGMON_MAX];
static bool visited[DIGMON_MAX];

static int count;

void count_digimons(int u)
{
	if (!visited[u])
	{
		count++;
		visited[u] = true;

		for (int i = 0; i < pos[u]; ++i)
			count_digimons(adj[u][i]);
	}
}

int main()
{
	int n, m, u, v;

	while (true)
	{
		if (scanf("%d %d ", &n, &m) == EOF)
			break;

		for (int i = 1; i <= n; ++i)
		{
			pos[i] = 0;
			visited[i] = false;
		}

		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d ", &u, &v);

			adj[u][pos[u]++] = v;
			adj[v][pos[v]++] = u;
		}

		scanf("%d ", &u);

		count = 0;
		count_digimons(u);

		printf("%d\n", count);
	}

	return 0;
}
