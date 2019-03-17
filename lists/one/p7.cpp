#include <iostream>
#include <ios>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
	map<string, map<string, int>> rules{
		{"tesoura", {
			{"papel",   1},
			{"lagarto", 1}}
		},
		{"papel", {
			{"pedra", 1},
			{"Spock", 1}}
		},
		{"pedra", {
			{"lagarto", 1},
			{"tesoura", 1}}
		},
		{"lagarto", {
			{"Spock", 1},
			{"papel", 1}}
		},
		{"Spock", {
			{"tesoura", 1},
			{"pedra",   1}}
		}
	};

	int i;
	string sheldon, raj;

	cin >> i;

	for (int j = 1; j <= i; j++)
	{
		cin >> sheldon >> raj;
		cout << "Caso #" << j;

		if (rules[sheldon][raj])
			cout << ": Bazinga!" << endl;
		else if (sheldon == raj)
			cout << ": De novo!" << endl;
		else
			cout << ": Raj trapaceou!" << endl;
	}

	return 0;
}