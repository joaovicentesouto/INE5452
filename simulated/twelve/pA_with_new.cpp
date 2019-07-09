#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <cmath>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX_WORD 5000

#define TWO(x, y) (x * MAX_WORD + y)
#define THREE(x, y, z) (x * MAX_WORD + y * 27 + z)

unordered_map<string, int> lang_to_vertex;

//! Graph variables
int count_langs;
int amount_words;
int * pos_verts;

int * adj;
int * pos_edges;
int * edges;
int * len;

//! Dijkstra variables
int * distances;
bool * visited;

static inline void connect(string & l1, string & l2, string & w)
{
	int v1, v2, i, j, k, l;
	int w0 = w[0] - 'a';
	int wl  = w.size();

	if (lang_to_vertex[l1])
		v1 = lang_to_vertex[l1];
	else
	{
		v1 = count_langs++;
		lang_to_vertex[l1] = v1;
	}

	if (lang_to_vertex[l2])
		v2 = lang_to_vertex[l2];
	else
	{
		v2 = count_langs++;
		lang_to_vertex[l2] = v2;
	}

	for (i = 0; i < pos_verts[v1]; ++i)
		if (adj[TWO(v1, i)] == v2)
			break;

	for (j = 0; j < pos_verts[v2]; ++j)
		if (adj[TWO(v2, j)] == v1)
			break;
	
	if (i == pos_verts[v1]) pos_verts[v1]++;
	if (j == pos_verts[v2]) pos_verts[v2]++;

	adj[TWO(v1, i)] = v2;
	adj[TWO(v2, j)] = v1;

	for (k = 0; k < pos_edges[TWO(v1, v2)]; ++k)
		if (edges[THREE(v1, v2, k)] == w0)
			break;
	
	if (k == pos_edges[TWO(v1, v2)])
	{
		pos_edges[TWO(v1, v2)]++;
		pos_edges[TWO(v2, v1)]++;
		
		len[THREE(v1, v2, w0)] = wl;
		len[THREE(v2, v1, w0)] = wl;

		edges[THREE(v1, v2, k)] = w0;
		edges[THREE(v2, v1, k)] = w0;
	}
	else
	{
		if (wl < len[THREE(v1, v2, k)])
		{
			len[THREE(v1, v2, k)] = wl;
			len[THREE(v2, v1, k)] = wl;
		}
	}

	// printf("connect %s (%d) to %s (%d) with %s | %c (%d) => [%d - %d]\n",
	// 	l1.c_str(), v1,
	// 	l2.c_str(), v2,
	// 	w.c_str(),
	// 	w[0], w0, len[v1][v2][k], len[v2][v1][l]
	// );
}

static inline int minimum_distance()
{
	int min_index;
	int min = INT_MAX;

	for (int v = 1; v <= amount_words; v++)
		if (!visited[v] && distances[v] <= min)
			min = distances[v], min_index = v;

	return min_index;
}

void dijkstra(int src, int dest)
{
	for (int i = 0; i <= amount_words; i++)
		distances[i] = INT_MAX, visited[i] = false;

	distances[src] = 0;

	// printf("Search %d to %d\n", src, dest);

	for (int count = 0; count < amount_words; count++)
	{
		int u = minimum_distance();

		// printf("Get u: %d with distance: %d\n", u, distances[u]);

		if (u == dest || (distances[u] == INT_MAX))
			return;

		visited[u] = true;

		for (int i = 0; i < pos_verts[u]; i++)
		{
			int v = adj[TWO(u, i)];

			if (visited[v])
				continue;

			for (int j = 0; j < pos_edges[TWO(u, v)]; j++)
			{
				int c = edges[THREE(u, v, j)];

				if ((distances[u] + len[THREE(u, v, c)]) < distances[v])
					distances[v] = distances[u] + len[THREE(u, v, c)];
			}
		}
	}
}

int main()
{
	char temp[51];

	adj = new int[MAX_WORD * MAX_WORD];
	edges = new int[MAX_WORD * MAX_WORD * 27];
	pos_edges = new int[MAX_WORD * MAX_WORD];
	len = new int[MAX_WORD * MAX_WORD * 27];
	distances = new int[MAX_WORD];
	visited = new bool[MAX_WORD];
	pos_verts = new int[MAX_WORD];

	while (true)
	{
		scanf("%d ", &amount_words);

		if (!amount_words)
			break;
        
        for (int i = 0; i <= amount_words; i++)
		{
			pos_verts[i] = 0;

			for (int j = 0; j <= amount_words; j++)
            	pos_edges[TWO(i, j)] = 0;
		}
		count_langs = 1;

		scanf("%s ", temp);
		string src(temp);
		scanf("%s ", temp);
		string dest(temp);

		for (int i = 0; i < amount_words; i++)
		{
			scanf("%s ", temp);
			string l1(temp);
			scanf("%s ", temp);
			string l2(temp);
			scanf("%s ", temp);
			string w(temp);

            connect(l1, l2, w);
		}

		int u = lang_to_vertex[src];
		int v = lang_to_vertex[dest];

		dijkstra(u, v);

		if (distances[v] != INT_MAX)
			printf("%d\n", distances[v]);
		else
			printf("impossivel\n");
	}

	delete adj;
	delete edges;
	delete pos_edges;
	delete len;
	delete distances;
	delete visited;
	delete pos_verts;

	return 0;
}
