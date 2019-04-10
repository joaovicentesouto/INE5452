#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    
    cin >> n;

    do
    {
        while(true)
        {
            int m, bigger;
            stack<int> station;
            vector<int> train;

            cin >> m;

            if (!m)
                break;

            train.insert(train.begin(), m);
            for (int i = 1; i < n; i++)
            {
                cin >> m;
                train.insert(train.begin(), m);
            }

            bigger = n;
            
            for (auto v : train)
            {
                if (v < bigger)
                    station.push(v);
                else
                    bigger--;
                
                while (station.size() && station.top() == bigger)
                {
                    station.pop();
                    bigger--;
                }
            }

            if (!station.size())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        cout << endl;
        cin >> n;
    } while (n);

	return 0;
}