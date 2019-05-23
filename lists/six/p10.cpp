#include <iostream>
#include <string>

using namespace std;

int main()
{
	string enigma, cribs;

	cin >> enigma >> cribs;

	int matches = 0;
	for (int i = 0; i < (enigma.size() - cribs.size() + 1); i++)
	{
		bool valid = true;
		for (int j = i, k = 0; k < cribs.size() && valid; ++j, ++k)
			valid = enigma[j] != cribs[k];
		
		matches += valid;
	}

	cout << matches << endl;

	return 0;
}
