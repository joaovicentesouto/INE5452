#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{
	double hours, velocity;

	cin >> hours >> velocity;

	cout << std::fixed << std::setprecision(3);
	cout << ((hours * velocity) / 12) << endl;

	return 0;
}