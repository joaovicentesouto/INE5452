#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	string word;

	while (cin >> word)
	{
		unordered_map<char, bool> odd;

		for (const auto & c : word)
			odd[c] = !odd[c];
		
		int amount_odd = 0;
		for (auto & [key, value] : odd)
		{
			if (value)
				amount_odd++;
		}

		if (amount_odd > 1)
			cout << amount_odd - 1 << endl;
		else
			cout << 0 << endl;
	}

	return (1);
}