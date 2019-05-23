#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
	int matriculas;

	cin >> matriculas;

	while (matriculas--)
	{
		string matr;

		cin >> matr;

		if (matr[0] != 'R' || matr[1] != 'A' || matr.size() != 20)
		{
			cout << "INVALID DATA" << endl;
			continue;
		}

		uint64_t value;
		istringstream iss(matr.substr(2));
		iss >> value;

		cout << value << endl;
	}

	return 0;
}
