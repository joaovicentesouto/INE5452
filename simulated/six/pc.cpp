#include <iostream>

using namespace std;

int main() 
{
	int canos, capacidade;

	cin >> canos >> capacidade;

    int precos[canos];
    int tamanhos[canos];

	for (int i = 0; i < canos; i++)
		cin >> tamanhos[i] >> precos[i];

    // Populate base cases
    int mat[canos + 1][capacidade + 1];

	for (int i = 0; i < canos + 1; i++)
		for (int j = 0; j < capacidade + 1; j++)
			mat[i][j] = 0;

    // Main logic
    for (int item = 1; item <= canos; item++)
    {
        for (int cap_atual = 1; cap_atual <= capacidade; cap_atual++)
        {
            int maxValWithoutCurr = mat[item - 1][cap_atual];
            int maxValWithCurr = 0;
            
            int weightOfCurr = tamanhos[item - 1];

            int vezes = 1;

            while (cap_atual >= (vezes * weightOfCurr))
            {
                maxValWithCurr = vezes * precos[item - 1];
                
                int remainingcap_atual = cap_atual - vezes * weightOfCurr;
                maxValWithCurr += mat[item - 1][remainingcap_atual];

                mat[item][cap_atual] = max(maxValWithoutCurr, maxValWithCurr);
            }
        }
    }

		cout << mat[canos][capacidade] << endl;

	return 0; 
}