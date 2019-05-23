#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	while (true)
	{
		int i, j;
		string text, pattern;

		cin >> i >> j;

		if (!i || !j)
			break;
		
		cin >> ws;
		getline(cin, text);
		cin >> ws;

		cin >> ws;
		getline(cin, pattern);
		cin >> ws;

		regex reg(pattern + " ");

		cout << endl << text << endl << pattern << endl;

		if (regex_search (text, reg))
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}
