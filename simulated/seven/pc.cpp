#include <iostream>
#include <string>
#include <vector>

using namespace std;

void kmp_table(string &w, vector<int> &t)
{
	int pos = 1;
	int cnd = 0;
	t[0] = -1;
	
	while (pos < w.size())
	{
		if (w[pos] == w[cnd])
			t[pos] = t[cnd];
		else
		{
			t[pos] = cnd;
			cnd = t[cnd];
			while (cnd >= 0 && w[pos] != w[cnd])
				cnd = t[cnd];
		}

		pos++;
		cnd++;
	}

	t[pos] = cnd;
}

int kmp_search(string &s, string &w, vector<int> &T)
{
	int j = 0;
	int k = 0;
	int nP = 0;

	while (j < s.size())
	{
		if (w[k] == s[j])
		{
			j++; k++;

			if (k == w.size())
			{
				s = s.substr(0, j-w.size()) + s.substr(j);

				return 1;
			}
		}
		else
		{
			k = T[k];
			if (k < 0)
			{
				j++; k++;
			}
		}
	}

	return 0;
}

int main()
{
	while (true)
	{
		int n, m;

		cin >> n >> m;

		if (!n && !m)
			break;

		vector<string> Ws(n);
		vector<vector<int>> Ts;

		for (int i = 0; i < n; ++i)
		{
			cin >> Ws[i];
			Ts.push_back(vector<int>(Ws.size()));

			kmp_table(Ws[i], Ts[i]);
		}

		int count = 0;

		while (m--)
		{
			string line;

			cin >> ws;
			getline(cin, line);
			cin >> ws;

			bool still_cleaning = true;

			while (still_cleaning && !line.empty())
			{
				int local_count = 0;
				for (int i = 0; i < Ws.size(); ++i)
					local_count += kmp_search(line, Ws[i], Ts[i]);

				still_cleaning = (local_count != 0);

				count += local_count;
			}
		}

		cout << count << endl;
	}

	return 0;
}
