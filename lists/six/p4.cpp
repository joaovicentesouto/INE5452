#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <cctype>

using namespace std;

int main()
{
	int cases;

	cin >> cases;

	while (cases--)
	{
		string line;
		unordered_map<char, int> count;
		unordered_map<int, set<char>> sets;

		cin >> ws;
		getline(cin, line);
		cin >> ws;

		int max_count = 0;
		for (auto c : line)
		{
			if (c == ' ')
				continue;
			
			c = tolower(c);
			
			count[c]++;

			if (count[c] > max_count)
				max_count = count[c];
			
			sets[count[c]].insert(c);
		}
		
		for (auto c : sets[max_count])
			cout << c;
		cout << endl;
	}

	return 0;
}
