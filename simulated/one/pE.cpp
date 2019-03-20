#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int quant, tipos;

	cin >> quant >> tipos;

	vector<int> rotulos(tipos);

	while (quant--)
	{
		int r;

		cin >> r;
		rotulos[r-1]++;
	}

	int envelopes = 0;

	while (true)
	{
		for (int i = 0; i < tipos; i++)
		{
			if (rotulos[i] == 0)
				goto exit;

			rotulos[i]--;
		}

		envelopes++;
	}

exit:
	cout << envelopes << endl;

	return 0;
}