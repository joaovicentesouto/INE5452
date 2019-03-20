#include <iostream>

using namespace std;

int main()
{
	int maria, joao;
	int jogadas;

	while (cin >> jogadas)
	{
		if (jogadas == 0)
			break;

		maria = joao = 0;

		while (jogadas-- > 0)
		{
			int one;
			cin >> one;

			if (one)
				joao++;
			else
				maria++;
		}

		cout << "Mary won " << maria << " times and John won " << joao << " times" << endl;
	}

	return 0;
}