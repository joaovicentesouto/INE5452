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
        unordered_map<string, set<string>> states;

		for (int i = 0; i < n; ++i)
		{
			string key(""), value("");
			
			cin >> aux;
			value += aux[0];

            for (int i = 0; i < (aux.size()-1); ++i)
			{
				key = value;
				value += aux[i+1];
				states[key].insert(value);
			}

			states[aux].insert("\0\1");
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
				string ch = string("") + line[i];

                auto curr = states[ch];

				if (curr.empty())
					continue;

				while (i < line.size())
				{
					ch += line[i+1];

					for (auto c : set<string>(curr))
					{
						if (c == "\0\1")
						{
							count++;
							curr.clear();
							break;
						}
						else if (c == ch)
							curr.insert(states[c].begin(), states[c].end());
						else
							curr.erase(c);
					}
					
					if (!curr.empty())
						i++;
					else
						break;
				}
            }
		}

		cout << count << endl;
	}

	return 0;
}
