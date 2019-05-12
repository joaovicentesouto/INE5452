//! References: geeksforgeeks
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	int n, teste = 1;

	while (cin >> n)
	{
		if (!n)
			break;
		
		string s;

		cin >> s;

		int cuts[n][n];
		bool substr_is_palindrome[n][n];

		for (int i = 0; i < n; i++)
		{
			substr_is_palindrome[i][i] = true;
			cuts[i][i] = 0;
		}

		for (int length = 2; length <= n; length++)
		{
			for (int i = 0; i < n - length + 1; i++)
			{
				int j = i + length - 1;

				if (length == 2)
					substr_is_palindrome[i][j] = (s[i] == s[j]);
				else
					substr_is_palindrome[i][j] = (s[i] == s[j]) && substr_is_palindrome[i + 1][j - 1];

				if (substr_is_palindrome[i][j])
					cuts[i][j] = 0;
				else
				{
					cuts[i][j] = numeric_limits<int>::max();
					for (int k = i; k <= j - 1; k++)
						cuts[i][j] = min(cuts[i][j], cuts[i][k] + cuts[k + 1][j] + 1);
				}
			}
		}

		cout << "Teste " << teste++ << endl;
		cout << (cuts[0][n - 1] + 1) << endl << endl;
	}

	return 0;
}
