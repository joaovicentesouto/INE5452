#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string letters;
	int size, index;

	while (cin >> letters)
	{
		cin >> size;

		while (size--)
		{
			cin >> index;
			cout << letters[index - 1];
		}

		cout << endl;
	}

	return 0;
}