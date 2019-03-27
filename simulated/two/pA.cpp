#include <iostream>

using namespace std;

class Racional
{
public:
	Racional() = default;
	Racional(int n, int d) : _n(n), _d(d) {}

	Racional add(Racional r2)
	{
		int n3 = (_n * r2._d + r2._n * _d);
		int d3 = (_d * r2._d);

		return Racional(n3, d3);
	}

	Racional sub(Racional r2)
	{
		int n3 = (_n * r2._d - r2._n * _d);
		int d3 = (_d * r2._d);

		return Racional(n3, d3);
	}

	Racional mult(Racional r2)
	{
		int n3 = (_n * r2._n);
		int d3 = (_d * r2._d);

		return Racional(n3, d3);
	}

	Racional div(Racional r2)
	{
		int n3 = (_n * r2._d);
		int d3 = (r2._n * _d);

		return Racional(n3, d3);
	}

	int mdc(int x, int y)
	{
		int a = max(x, y);
		int b = min(x, y);

		if (a % b == 0)
			return b;
		else
			return mdc(b, (a % b));
	}

	Racional simplifica()
	{
		int m = mdc(_n, _d);

		return Racional(_n/m, _d/m);
	}

	void print()
	{
		int n = (_n < 0 ? -1 : 1) * _n;
		int d = (_d < 0 ? -1 : 1) * _d;

		if (_n < 0 || _d < 0)
			cout << "-";
		cout << n << "/" << d;
	}

	int _n{0}, _d{0};
};

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char op, aux;
		int n, d;

		cin >> n >> aux >> d;
		Racional r1(n, d);

		cin >> op;

		cin >> n >> aux >> d;
		Racional r2(n, d);

		Racional r3, sp;
		switch(op)
		{
			case '+':
				r3 = r1.add(r2);
				sp = r3.simplifica();
				r3.print();
				cout << " = ";
				sp.print();
				break;
			case '-':
				r3 = r1.sub(r2);
				sp = r3.simplifica();
				r3.print();
				cout << " = ";
				sp.print();
				break;
			case '*':
				r3 = r1.mult(r2);
				sp = r3.simplifica();
				r3.print();
				cout << " = ";
				sp.print();
				break;
			case '/':
				r3 = r1.div(r2);
				sp = r3.simplifica();
				r3.print();
				cout << " = ";
				sp.print();
				break;
			default:
				break;
		}

		cout << endl;
	}

	return 0;
}