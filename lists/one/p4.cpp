#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>

using namespace std;

int main()
{
	double a, b, c;
	double delta, r1, r2;

	cin >> a >> b >> c;

	delta = pow(b, 2) - (4 * a * c);

	if (a == 0 || delta < 0)
		cout << "Impossivel calcular" << endl;

	else
	{
		r1 = (-b + sqrt(delta)) / (2 * a);
		r2 = (-b - sqrt(delta)) / (2 * a);

		cout << std::fixed << std::setprecision(5);
		cout << "R1 = " << r1 << endl;
		cout << "R2 = " << r2 << endl;
	}

	return 0;
}