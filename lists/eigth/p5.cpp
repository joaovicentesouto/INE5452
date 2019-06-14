#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

enum Side
{
	STAND = -1,
	LEFT  =  0,
	RIGHT =  1
};

static int people;
static int pos[102];
static int status[102];
static int adj[102][102];

bool sitting_down(int s)
{
	queue<int> q;

	status[s] = Side::LEFT;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i = 0; i < pos[u]; i++)
		{
			int v = adj[u][i];

			if (status[v] == Side::STAND)
			{
				status[v] = (status[u] + 1) % 2;
				q.push(v);
			}
			else if (status[u] == status[v])
				return false;
		}
	}

	return true;
}

bool can_partitionate()
{
	for (int u = 1; u <= people; ++u)
	{
		if (status[u] == Side::STAND)
			if (!sitting_down(u))
				return false;
	}

	return true;
}

int main()
{
	int n, m, u, v, cases = 1;

	while (cin >> n >> m)
	{
		people = n;

		for (int i = 1; i <= n; ++i)
		{
			pos[i] = 0;
			status[i] = Side::STAND;
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v;

			adj[u][pos[u]++] = v;
			adj[v][pos[v]++] = u;
		}

		cout << "Instancia " << cases++ << endl;

		if (can_partitionate())
			cout << "sim" << endl;
		else
			cout << "nao" << endl;
		cout << endl;
	}

	return 0;
}
