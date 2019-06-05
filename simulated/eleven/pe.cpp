#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Graph
{
	int n{1};
	unordered_map<string, int> names;
	unordered_map<int, unordered_set<int>> adj;
	unordered_map<int, bool> visited;
};

int count_component(Graph &g, int u)
{
	g.visited[u] = true;

	for (int v : g.adj[u])
	{
		if (!g.visited[v])
			count_component(g, v);
	}

	return (1);
}

int main()
{
	int m, n;
	int u, v;

	cin >> m >> n;

	Graph g;

	for (int i = 1; i <= m; ++i)
		g.visited[i];

	string name1, relation, name2;

	for (int i = 0; i < n; ++i)
	{
		cin >> name1 >> relation >> name2;

		if (g.names[name1] == 0)
		{
			u = g.n++;
			g.names[name1] = u;
		}
		else
			u = g.names[name1];


		if (g.names[name2] == 0)
		{
			v = g.n++;
			g.names[name2] = v;
		}
		else
			v = g.names[name2];

		g.adj[u].insert(v);
		g.adj[v].insert(u);
	}

	int count = 0;

	for (const auto & p : g.visited)
	{
		if (!p.second)
			count += count_component(g, p.first);
	}

	cout << count << endl;

	return 0;
}