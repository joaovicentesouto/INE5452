#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
public:
    Graph() {}

	void create(int u)
	{
		visited[u] = false;
		n++;
	}

	void connect(int u, int v)
	{
		adj[u].insert(v);
		adj[v].insert(u);
	}

	int n{0};
	unordered_map<int, unordered_set<int>> adj;
    unordered_map<int, bool> visited;
};

int position(int x, int y)
{
	return ((x + 1) * 10000) + (y + 1);
}

void visit(Graph & g, int u)
{
	if (g.visited[u])
		return;
	
	g.visited[u] = true;

	for (auto v : g.adj[u])
		visit(g, v);
}

int main()
{
	int X, Y;

	cin >> X;
	cin >> Y;

	vector<string> board(X+1);

	for (int i = 0; i < X; ++i)
		cin >> board[i];
	
	Graph g;
	
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			if (board[i][j] == 'o')
				continue;
			
			int v = position(i, j);

			g.create(v);
			
			if (i > 0)
				if (board[i - 1][j] == '.')
					g.connect(position(i - 1, j), v);

			if (j > 0)
				if (board[i][j - 1] == '.')
					g.connect(position(i, j - 1), v);
		}
	}

	int groups = 0;

	for (const auto & [u, visited] : g.visited)
	{
		if (!visited)
		{
			visit(g, u);
			groups++;
		}
	}

	cout << groups << endl;

	return 0;
}