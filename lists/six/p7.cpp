#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	int n;
	string text, pattern;

	cin >> text >> n;

	while (n--)
	{
		unsigned u;
		cin >> u;

		char c = 'a' + u - 1;

		pattern += c;
	}

	cout << text << endl;
	cout << pattern << endl;

	regex reg(pattern);

	if (regex_search (text, reg))
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}
