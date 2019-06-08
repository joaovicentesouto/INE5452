#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

enum Color
{
    WHITE = 0,
    GRAY  = 1,
    BLACK = 2
};

class Graph
{
public:
    Graph(int n_) : n(n_), adj(n_), visited(n_) {}

    int n;
	unordered_map<int, unordered_set<int>> adj;
	unordered_map<int, Color> visited;
};

int deep_search(Graph &g, int u)
{
    if (g.visited[u] == Color::GRAY)
        return true;

	g.visited[u] = Color::GRAY;

	for (const auto & w : g.adj[u])
    {
        if (g.visited[w] != Color::BLACK)
            if (deep_search(g, w))
                return true;
    }

    g.visited[u] = Color::BLACK;

	return false;
}

bool contains_loop(Graph &g)
{
    for (int i = 1; i <= g.n; ++i)
    {
        if (g.visited[i] != Color::BLACK)
            if (deep_search(g, i))
                return true;
    }

    return false;
}

int main()
{
    int cases, u, v;

    cin >> cases;

	while (cases--)
	{
		int docs, dependences;

		cin >> docs >> dependences;

        Graph g(docs);

        for (int i = 0; i < dependences; ++i)
        {
            cin >> u >> v;
            g.adj[u].insert(v);
        }

        if (contains_loop(g))
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;
	}

	return 0;
}
