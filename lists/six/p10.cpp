#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define TOTAL (1025 * 1025)

static int amount = 0;
static int pos[TOTAL];
static int adj[TOTAL][TOTAL];
static bool visited[TOTAL];
static unordered_map<int, int> xy_to_vertex;

int position(int x, int y)
{
	return ((x + 1) * 10000) + (y + 1);
}

void visit(int u)
{
	if (visited[u])
		return;
	
	visited[u] = true;

	for (int i = 0; i < pos[u]; ++i)
		visit(adj[u][i]);
}

int main()
{
	int X, Y;

	cin >> X;
	cin >> Y;

	vector<string> board(X+1);

	for (int i = 0; i < X; ++i)
		cin >> board[i];
	
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			if (board[i][j] == 'o')
				continue;
			
			int u = amount++;
			xy_to_vertex[position(i, j)] = u;
			
			if (i > 0)
			{
				if (board[i - 1][j] == '.')
				{
					int v = xy_to_vertex[position(i - 1, j)];
					adj[u][pos[u]++] = v;
					adj[v][pos[v]++] = u;
				}
			}

			if (j > 0)
			{
				if (board[i][j - 1] == '.')
				{
					int v = xy_to_vertex[position(i, j - 1)];
					adj[u][pos[u]++] = v;
					adj[v][pos[v]++] = u;
				}
			}
		}
	}

	int groups = 0;

	for (int u = 0; u < amount; ++u)
	{
		if (!visited[u])
		{
			visit(u);
			groups++;
		}
	}

	cout << groups << endl;

	return 0;
}