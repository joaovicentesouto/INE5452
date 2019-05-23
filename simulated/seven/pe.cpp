#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t cases;

	cin >> cases;

	while (cases--)
	{
		int i = -1, j = -1;
		string w0, w1, q;

		cin >> w0 >> w1 >> q;


		for (int k = 0; k < q.size(); ++k)
		{
			if (q[k] == '_')
			{
				if (i == -1)
				{
					i = k;
					continue;
				}

				j = k;
				break;
			}
		}

		if (w0[i] == w1[j] || w0[j] == w1[i])
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}

	return (1);
}