#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	static unordered_map<char, int> leds{
		{'0', 6}, {'1', 2}, {'2', 5}, {'3', 5}, {'4', 4},
		{'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}
	};

	int cases;
	string number;

	cin >> cases;

	while (cases--)
	{
		cin >> number;

		int count = 0;
		for (auto & c : number)
			count += leds[c];
		
		cout << count <<  " leds" << endl;
	}

	return 0;
}
