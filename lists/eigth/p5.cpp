#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

enum Side
{
    STAND = 0,
    LEFT  = 1,
    RIGHT = 2
};

class Graph
{
public:
    Graph(int n_) : n(n_), adj(n_), status(n_) {}

    int n;
	unordered_map<int, unordered_set<int>> adj;
    unordered_map<int, Side> status;
};

void put(Graph & g, int u, int v)
{
    if (g.status[u] == Side::LEFT)
        g.status[v] = Side::RIGHT;
    else
        g.status[v] = Side::LEFT;
}

bool sitting_down(Graph &g, int u)
{
	for (const auto & v : g.adj[u])
    {
        //! Already seated.
        if (g.status[v] != Side::STAND)
        {
            if (g.status[u] == g.status[v])
                return false;
        }

        //! Standing
        else
        {
            put(g, u, v);

            if (!sitting_down(g, v))
                return false;
        }
    }

	return true;
}

bool can_partitionate(Graph &g)
{
    for (int i = 1; i <= g.n; ++i)
    {
        if (g.status[i] == Side::STAND)
        {
            g.status[i] = Side::STAND;

            for (const auto & v : g.adj[i])
            {
                if (g.status[v] != Side::STAND)
                {
                    put(g, v, i);
                    break;
                }
            }

            if (g.status[i] == Side::STAND)
                g.status[i] = Side::LEFT;

            if (!sitting_down(g, i))
                return false;
        }
    }

    return true;
}

int main()
{
    int n, m, u, v, cases = 1;

	while (cin >> n >> m)
	{
        Graph g(n);

        // if (cases == 32)
        //     cout << n << " . " << m << endl;

        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v;
            // if (cases == 32)
            //     cout << u << " . " << v << endl;
            g.adj[u].insert(v);
            g.adj[v].insert(u);
        }

        cout << "Instancia " << cases++ << endl;

        if (can_partitionate(g))
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
        cout << endl;
	}

	return 0;
}
