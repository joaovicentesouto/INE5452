#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int cur;

bool visited[110];
int dist[110];

vector<pair<int, int>> adj[110];
int parent[110];

int m, n;
int x, y, z;

void prim(void)
{
	dist[1] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

	queue.push({dist[1], 1});

	while (!queue.empty())
	{
		while (!queue.empty())
		{
			cur = queue.top().second;

			queue.pop();

			if (!visited[cur])
				break;

			cur = -1;
		}

		if (cur < 0)
			break;

		// printf("Cur: %d\n", cur);

		visited[cur] = true;

		for (size_t i = 0; i < adj[cur].size(); ++i)
		{
			int a = adj[cur][i].first;
			int b = adj[cur][i].second;

			if (dist[b] > a && !visited[b])
			{
				dist[b] = a;
				queue.push({dist[b], b});
				parent[b] = cur;
			}
		}
	}
}

void UGRAPHmstKruskal0(edge mst[]) 
{ 
   vertex chefe[1000];
   for (vertex v = 0; v < G->V; ++v) 
      chefe[v] = v;
   int k = 0;
   while (true) {
      // a floresta tem arestas mst[0..k-1]
      vertex x, y;
      int min = INFINITY;
      for (vertex v = 0; v < G->V; ++v) {
         for (link a = G->adj[v]; a != NULL; a = a->next) {
            vertex w = a->w; int c = a->cst;
            if (v < w && chefe[v] != chefe[w] && c < min) {
               x = v, y = w;
               min = c;
            }
         }
      }
      if (min == INFINITY) return; 
      mst[k++] = EDGE( x, y, min);
      vertex v0 = chefe[x], w0 = chefe[y]; // 1
      for (vertex v = 0; v < G->V; ++v)    // 2
         if (chefe[v] == w0)               // 3
            chefe[v] = v0;                 // 4
   }
}

int main()
{
	int cases = 1;

	while (true)
	{
		scanf("%d ", &n);

		if (n == 0)
			break;

		scanf("%d ", &m);

		for (int i = 1; i <= n; ++i)
		{
			visited[i] = false;
			parent[i] = 0;
			dist[i] = INT_MAX;

			adj[i].clear();
		}

		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &x, &y, &z);

			adj[x].push_back({z, y});
			adj[y].push_back({z, x});
		}

		prim();

		printf("Teste %d\n", cases++);

		for (int i = 1; i <= n; ++i)
		{
			if (parent[i] > 0)
			{
				if (i <= parent[i])
					printf("%d %d\n", i, parent[i]);
				else
					printf("%d %d\n", parent[i], i);
			}
		}

		printf("\n");
	}
}