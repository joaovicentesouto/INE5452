#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int mod, amount;
        unordered_map<int, vector<int>> map;

        cin >> mod >> amount;

        for (int j = 0; j < amount; j++)
        {
            int aux;
            cin >> aux;
            map[aux % mod].push_back(aux);
        }

        for (int j = 0; j < mod; j++)
        {
            cout << j;
            for (auto x : map[j % mod])
                cout << " -> " << x;
            cout << " -> \\" << endl;
        }

        if (i < n-1)
            cout << endl;
    }

	return 0;
}