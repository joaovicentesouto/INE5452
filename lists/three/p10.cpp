#include <iostream>
#include <vector>
#include <set>

using namespace std;

using Employee = pair<int, int>;
using EmployeeSet = set<Employee>;

int main()
{
	int f, c, aux, products, worse_time{0};
	EmployeeSet market;


	cin >> f >> c;

	vector<int> emp_time(f);

	for (auto i = 0; i < f; i++)
	{
		cin >> aux;
		emp_time[i] = aux;
		market.insert({0, i});
	}

	for (int i = 0; i < c; i++)
    {
		cin >> products;

        auto emp = *(market.begin());
        market.erase(emp);
 
        emp.first += emp_time[emp.second] * products;
 
        market.insert(emp);
 
        worse_time = emp.first > worse_time ? emp.first : worse_time;
    }
 
    cout << worse_time << endl;
 
    return 0;
}