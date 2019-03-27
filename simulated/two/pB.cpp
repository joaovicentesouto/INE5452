#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a2;
		int amount;
		string product;
		double price;
		double result;
		unordered_map<string, double> prices;

		cin >> amount;
		for (int j = 0; j < amount; j++)
		{
			cin >> product >> price;
			prices[product] = price;
		}

		cin >> amount;
		result = 0;
		for (int j = 0; j < amount; j++)
		{
			cin >> product >> a2;
			result += prices[product] * a2;
		}

		cout << std::fixed << std::setprecision(2);
		cout << "R$ " << result << endl;
	}

	return 0;
}