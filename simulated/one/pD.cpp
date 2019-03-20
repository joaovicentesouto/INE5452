#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<char, int> index{{'A', 0}, {'B', 1}, {'C', 3}, {'D', 4}, {'E', 5}};

	int assocs, teste = 1;
	while (true)
	{
		cin >> assocs;
		if (assocs == 0)
			break;


		vector<vector<int>> senha(6);

		for (int i = 0; i < assocs; i++)
		{
			map<char, vector<int>> maps;
			int digito;
			cin >> digito;
			maps['A'].push_back(digito);
			cin >> digito;
			maps['A'].push_back(digito);

			cin >> digito;
			maps['B'].push_back(digito);
			cin >> digito;
			maps['B'].push_back(digito);

			cin >> digito;
			maps['C'].push_back(digito);
			cin >> digito;
			maps['C'].push_back(digito);

			cin >> digito;
			maps['D'].push_back(digito);
			cin >> digito;
			maps['D'].push_back(digito);

			cin >> digito;
			maps['E'].push_back(digito);
			cin >> digito;
			maps['E'].push_back(digito);

			char letra;

			cin >> letra;
			senha[0].push_back(maps[letra][0]);
			senha[0].push_back(maps[letra][1]);

			cin >> letra;
			senha[1].push_back(maps[letra][0]);
			senha[1].push_back(maps[letra][1]);

			cin >> letra;
			senha[2].push_back(maps[letra][0]);
			senha[2].push_back(maps[letra][1]);

			cin >> letra;
			senha[3].push_back(maps[letra][0]);
			senha[3].push_back(maps[letra][1]);

			cin >> letra;
			senha[4].push_back(maps[letra][0]);
			senha[4].push_back(maps[letra][1]);

			cin >> letra;
			senha[5].push_back(maps[letra][0]);
			senha[5].push_back(maps[letra][1]);
		}

		cout << "Teste " << teste++ << endl;
		int ____senha;


		for (int d = 0; d < 5; d++)
		{
			int d1 = senha[d][0];
			int d2 = senha[d][1];
			for (int ass = 1; ass < assocs; ass++)
			{
				int d3 = senha[d][ass*2];
				int d4 = senha[d][ass*2 + 1];

				if (d3 != d1 && d3 != d2)
				{
					____senha = d4;
					break;
				}
				else if (d4 != d1 && d4 != d2)
				{
					____senha = d3;
					break;
				}
			}

			cout << ____senha << " ";
		}

		int d1 = senha[5][0];
		int d2 = senha[5][1];
		for (int ass = 1; ass < assocs; ass++)
		{
			int d3 = senha[5][ass*2];
			int d4 = senha[5][ass*2 + 1];

			if (d3 != d1 && d3 != d2)
			{
				____senha = d4;
				break;
			}
			else if (d4 != d1 && d4 != d2)
			{
				____senha = d3;
				break;
			}
		}

		cout << ____senha << " " << endl << endl;
	}

	return 0;
}