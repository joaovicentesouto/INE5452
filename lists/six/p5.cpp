#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, m, instances = 1;

	while (cin >> n >> m)
	{
		vector<string> N(n);
		vector<string> M(m);

		for (int i = 0; i < n; ++i)
			cin >> N[i];
		
		for (int i = 0; i < m; ++i)
			cin >> M[i];
		
		cout << "Instancia " << instances++ << endl;

		bool match = false;
		for (int i = 0; i <= (n - m); ++i)
		{
			for (int j = 0; j <= (n - m); ++j)
			{
				bool valid = true;
				for (int x = 0; x < m && valid; ++x)
					for (int y = 0; y < m && valid; ++y)
						valid = N[x+i][y+j] == M[x][y];
				
				if (valid)
				{
					match = true;
					cout << j << " " << i << endl;
				}
			}
		}

		if (!match)
			cout << "nenhuma ocorrencia" << endl;
		cout << endl;
	}

	return 0;
}
