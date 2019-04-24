#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

struct Cano
{
	Cano(int tamanho, int preco) :
		t(tamanho),
		p(preco)
	{
		p_tamanho = ((double) preco) / ((double) tamanho);
	}

	int t, p;
	double p_tamanho;
};

int main(void)
{
	int casos, tamanho_total;

	cin >> casos >> tamanho_total;

	vector<Cano> canos;

	for (int i = 0; i < casos ; i ++) {
		int tamanho, preco;
		cin >> tamanho >> preco;
		canos.emplace_back(tamanho, preco);
	}

	sort(
		canos.begin(),
		canos.end(),
		[=](const Cano &a, const Cano &b) 
		{
		    return a.p_tamanho > b.p_tamanho; 
		}
	); 

	int total = 0;


	cout.precision(10);

	for (auto & cano : canos)
	{
		cout << cano.t << " " << cano.p << " " << cano.p_tamanho << endl;

		while (tamanho_total >= cano.t)
		{
			tamanho_total -= cano.t;
			total += cano.p;
		}

		// cout << tamanho_total << " - " << total << endl;
	}

	cout << total << endl;
}
