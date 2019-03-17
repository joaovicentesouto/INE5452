#include <iostream>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{
	int test_cases_amount;
	int total_animals = 0;
	int total_rabbits = 0;
	int total_rats = 0;
	int total_frogs = 0;

	cin >> test_cases_amount;

	while (test_cases_amount--)
	{
		int animals_amount;
		char species;

		cin >> animals_amount;
		cin >> species;

		switch (species)
		{
		case 'C':
			total_rabbits += animals_amount;
			break;
		case 'R':
			total_rats += animals_amount;
			break;
		case 'S':
			total_frogs += animals_amount;
			break;

		default:
			return (-1);
		}

		total_animals += animals_amount;
	}

	cout << std::fixed << std::setprecision(2);
	cout << "Total: " << total_animals << " cobaias" << endl
		 << "Total de coelhos: " << total_rabbits << endl
		 << "Total de ratos: " << total_rats << endl
		 << "Total de sapos: " << total_frogs << endl
		 << "Percentual de coelhos: " << (((double) total_rabbits / total_animals) * 100) << " %" << endl
		 << "Percentual de ratos: " << (((double) total_rats / total_animals) * 100) << " %" << endl
		 << "Percentual de sapos: " << (((double) total_frogs / total_animals) * 100) << " %" << endl;

	return 0;
}