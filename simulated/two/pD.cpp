#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int n;
	int p, q;
	int search;
	

	while (cin >> n)
	{
		unordered_map<int, int> map;

		for (int i = 0; i < n; i++)
			for (cin >> p >> q; p <= q; p++)
				map[p]++;

		cin >> search;

		
		int amount = 0;
		for (int i = 0; i < search; i++)
			amount += map[i];

		if (!map[search])
			cout << search << " not found"<< endl;
		else
			cout << search << " found from " << amount << " to " << (amount + map[search]-1) << endl;
	}

	return 0;
}