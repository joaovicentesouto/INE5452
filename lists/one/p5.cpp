#include <iostream>

using namespace std;

int main()
{
	int moves;
	int x1, y1, x2, y2;

	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		if (!x1 && !y1 && !x2 && !y2)
			break;

		moves = 0;

		for (; x1 != x2 && y1 != y2;)
		{
			x1 += x1 < x2 ? 1 : -1;
			y1 += y1 < y2 ? 1 : -1;
			moves = 1;
		}

		if (x1 != x2 || y1 != y2)
			moves++;

		cout << moves << endl;
	}

	return 0;
}