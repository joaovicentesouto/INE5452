//! References https://www.life2coding.com/uri-online-judge-solution-1539-telecom-company-intermediate-problem/

#include <bits/stdc++.h>

#define INF 123112512.00
#define ERROR 1e-9

using namespace std;

struct point
{
	int x, y, r;

	point() {x = y = r = 0;}
	point(int _x, int _y, int _r) : x(_x), y(_y), r(_r){}
};

int n;
double distances[105];
vector<vector<pair<double, int>>> pontos;

double dist(point &a, point &b)
{
	return (hypot(a.x - b.x, a.y - b.y));
}

void dijkstra(int s)
{
	for (int i = 0 ; i < n ; ++i)
		distances[i] = INF;

	distances[s] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>> , greater<pair<double, int>>> q;
	q.push(make_pair(0., s));

	while (!q.empty())
	{
		pair<double, int> u = q.top(); q.pop();

		int v = u.second;

		if (u.first - distances[v] > ERROR)
			continue;

		for (int i = 0 ; i < pontos[v].size(); ++i)
		{
			int v2 = pontos[v][i].second;
			if (distances[v2] - (distances[v] + pontos[v][i].first) > ERROR)
			{
				distances[v2] = distances[v] + pontos[v][i].first;
				q.push(make_pair(distances[v2], v2));
			}
		}
	}
}
int main()
{
	int u, v , w, c;
	point input[105];

	while (1)
	{
		scanf("%d", &n);
		if (!n) return 0;

		pontos.clear();
		pontos.assign(n, vector<pair<double, int>>());

		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			input[i] = (point(u, v, w));
		}

		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n; ++j)
			{
				double d = dist(input[i], input[j]);
				if (input[i].r - d > ERROR)
					pontos[i].push_back(make_pair(d, j));
			}

		scanf("%d", &c);

		while (c--)
		{
			scanf("%d %d", &u, &v);
			--u, --v;

			dijkstra(u);

			if (fabs(distances[v] - INF) < ERROR)
				printf("-1\n");
			else
				printf("%d\n", (int)(distances[v]));
		}
	}
}