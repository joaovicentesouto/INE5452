#include <iostream>
#include <string>

using namespace std;

#define CROW_BLINKS_MAX 3

int main()
{
	int sum, blinks = 0;
	string crow;

	while (blinks < CROW_BLINKS_MAX)
	{
		cin >> crow;

		if (crow == "caw")
		{
			cin >> crow;
			blinks++;

			cout << sum << endl;
			sum = 0;
		}
		else
		{
			int tmp = 0;
			tmp |= crow[2] == '*' ? 1 << 0 : 0;
			tmp |= crow[1] == '*' ? 1 << 1 : 0;
			tmp |= crow[0] == '*' ? 1 << 2 : 0;

			sum += tmp;
		}
	}

	return 0;
}