#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        string line1, line2;
        unordered_map<string, string> map;

        cin >> a >> b;
        getline(cin, line1);

        for (int j = 0; j < a; j++)
        {
            getline(cin, line1);
            getline(cin, line2);
            map[line1] = line2;
        }

        for (int j = 0; j < b; j++)
        {
            bool first = true;
            string temp;
            getline(cin, line1);
            stringstream iss(line1);

            while (iss >> temp)
            {
                if (map[temp] == "")
                    cout << (first? "" : " ") << temp;
                else
                    cout << (first? "" : " ") << map[temp];

                first = false;
            }

            cout << endl;
        }

        cout << endl;
    }

	return 0;
}