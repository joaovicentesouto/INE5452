#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	string aux;

	while (cin >> aux)
	{
		string frase;
		unordered_map<char, bool> vogais;

		for (auto & c : aux)
			vogais[c] = true;

		cin >> ws;
		getline(cin, frase);
		cin >> ws;

		int quant = 0;

		for (auto & c : frase)
			if (vogais[c])
				quant++;
		
		cout << quant << endl;
	}

	return (1);
}