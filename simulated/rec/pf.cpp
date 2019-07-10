#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n, N, L, p, l, c, v;

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i)
	{
		map<int, map<int, int>> matrix;

		scanf("%d %d ", &N, &L);

		for (int j = 0; j < L; ++j)
		{
			scanf("%d %d %d %d", &p, &l, &c, &v);

			matrix[l][c] += v;
		}

		for (const auto & x : matrix)
			for (const auto & y : x.second)
				printf("%d %d %d\n", x.first, y.first, y.second);

		if (i < n-1)
			printf("\n");
	}

	return 0;
}