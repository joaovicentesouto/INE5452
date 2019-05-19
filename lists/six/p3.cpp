#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	int cases;

	cin >> cases;
	cin >> ws;

	while (cases--)
	{
		string diets, breakfast, moon;
		set<char> diet;
		unordered_map<char, bool> exist;

		getline(cin, diets);

		for (auto c : diets)
		{
			exist[c] = true;
			diet.insert(c);
		}

		getline(cin, breakfast);

		bool valid = true;

		for (auto c : breakfast)
		{
			if (exist[c])
			{
				diet.erase(c);
				exist[c] = false;
			}
			else
			{
				cout << "CHEATER" << endl;
				valid = false;
				break;
			}
		}

		getline(cin, moon);

		for (auto c : moon)
		{
			if (!valid)
				break;

			if (exist[c])
			{
				diet.erase(c);
				exist[c] = false;
			}
			else
			{
				cout << "CHEATER" << endl;
				valid = false;
				break;
			}
		}

		if (!valid)
			continue;

		for (auto & c : diet)
			cout << c;
		cout << endl;
	}

	return 0;
}
