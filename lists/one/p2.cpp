#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{
	string name;
	double salary, sales;

	cin >> name >> salary >> sales;

	cout << std::fixed << std::setprecision(2);
	cout << "TOTAL = R$ " << (salary + 0.15 * sales) << endl;

	return 0;
}