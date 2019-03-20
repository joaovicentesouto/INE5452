#include <iostream>

using namespace std;

int main()
{
	int a1, a2, a3;
	int t1, t2, t3;
	
	cin >> a1 >> a2 >> a3;

	t1 = a2*2 + a3*2*2;
	t2 = a1*2 + a3*2;
	t3 = a1*2*2 + a2*2;

	int menor = t1;
	menor = (t2 <= menor) ? t2 : menor;
	menor = (t3 <= menor) ? t3 : menor;

	cout << menor << endl;

	return 0;
}