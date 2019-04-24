#include <iostream>

using namespace std;

int main() 
{
	int casos = 1;

	while (true)
	{
		int estante, capacidade;
		cin >> estante >> capacidade;

		if (!estante && !capacidade)
			break;

	    int interesses[estante];
	    int pesos[estante];

		for (int i = 0; i < estante; i++)
			cin >> pesos[i] >> interesses[i];

	    // Populate base cases
	    int mat[estante + 1][capacidade + 1];

		for (int i = 0; i < estante + 1; i++)
			for (int j = 0; j < capacidade + 1; j++)
				mat[i][j] = 0;

	    // Main logic
	    for (int item = 1; item <= estante; item++)
	    {
	        for (int cap_atual = 1; cap_atual <= capacidade; cap_atual++)
	        {
	            int interesse_maximo_sem_mim = mat[item - 1][cap_atual];
	            int interesse_maximo_comigo = 0;
	            
	            int weightOfCurr = pesos[item - 1];
	            if (cap_atual >= weightOfCurr)
	            {
	                interesse_maximo_comigo = interesses[item - 1];
	                
	                int resto_da_capacidade_comigo = cap_atual - weightOfCurr;
	                interesse_maximo_comigo += mat[item - 1][resto_da_capacidade_comigo];
	            }
	            
	            mat[item][cap_atual] = max(interesse_maximo_sem_mim, interesse_maximo_comigo);
	        }
	    }

		cout << "Caso " << casos++ << ": " << mat[estante][capacidade] << endl;
	}

	return 0; 
}