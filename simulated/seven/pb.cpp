#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	while (true)
	{
		int n, m;

		cin >> n >> m;

		if (!n && !m)
			break;

        string aux;
        unordered_map<char, set<string>> map;

		for (int i = 0; i < n; ++i)
		{
			cin >> aux;
            map[aux[0]].insert(aux);
		}

		int count = 0;

		while (m--)
		{
			string line;

			cin >> ws;
			getline(cin, line);
			cin >> ws;

			for (int i = 0; i < line.size(); ++i)
            {
                for (auto & e : map[line[i]])
                {
                    for (int j = 0; j <= e.size() && (i + j) <= line.size(); ++j)
                    {
                        if (j == e.size())
                        {
                            count++;
                            i += j;

                            break;
                        }

                        if (line[i + j] != e[j])
                            break;
                    }
                }
            }
		}

		cout << count << endl;
	}

	return 0;
}
