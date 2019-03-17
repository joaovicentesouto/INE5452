#include <iostream>
#include <ios>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
	map<string, string> morse_to_alpha{
		{"=.===",         "a"},
		{"===.=.=.=",     "b"},
		{"===.=.===.=",   "c"},
		{"===.=.=",       "d"},
		{"=",             "e"},
		{"=.=.===.=",     "f"},
		{"===.===.=",     "g"},
		{"=.=.=.=",       "h"},
		{"=.=",           "i"},
		{"=.===.===.===", "j"},
		{"===.=.===",     "k"},
		{"=.===.=.=",     "l"},
		{"===.===",       "m"},
		{"===.=",         "n"},
		{"===.===.===",   "o"},
		{"=.===.===.=",   "p"},
		{"===.===.=.===", "q"},
		{"=.===.=",       "r"},
		{"=.=.=",         "s"},
		{"===",           "t"},
		{"=.=.===",       "u"},
		{"=.=.=.===",     "v"},
		{"=.===.===",     "w"},
		{"===.=.=.===",   "x"},
		{"===.=.===.===", "y"},
		{"===.===.=.=",   "z"},
	};

	int i, points = 0;
	string line, aux;

	cin >> i;

	while(i-- > 0)
	{
		cin >> line;

		aux = "";
		points = 0;

		for (auto letter : line)
		{
			switch (letter)
			{
				case '=':
					if (points == 1) { aux += "."; points = 0; }
					if (points == 3) { cout << morse_to_alpha[aux]; aux = ""; points = 0; }
					aux += "=";
					break;

				case '.':
					points++;
					if (points == 7) {
						cout << morse_to_alpha[aux] << " ";
						aux = "";
						points = 0;
					}
					break;
			
				default:
					break;
			}
		}

		cout << morse_to_alpha[aux] << endl;
	}

	return 0;
}