//! Referência: http://codesoeasy.weebly.com/home/vonny-vonny-and-her-dominos
#include <stdio.h>

//! Variáveis globais
int visitados[7][8];
int tabuleiro[7][8];
int dominos[7][7] = { [0 ... 6] = { [0 ... 6] = 1 } };
int completos = 0;

//! Macros para aumentar a legibilidade
#define NAO_VISITADO(tx, ty) (!visitados[tx][ty])
#define VISITA(vx, vy, tx, ty) (visitados[vx][vy] = visitados[tx][ty] = 1)
#define DESVISITA(vx, vy, tx, ty) (visitados[vx][vy] = visitados[tx][ty] = 0)
#define PEGA_PECA(px, py) (dominos[px][py] = dominos[py][px] = 0)
#define DEVOLVE_PECA(px, py) (dominos[px][py] = dominos[py][px] = 1)
#define DENTRO(alvo, inferior, superior) ((inferior <= alvo) && (alvo < superior))

//! Função recursiva para ir alocando as peças
void aloca_domino(int x, int y)
{
	//! Consegui varrer todo o tabileiro colocando peças
	if(x == 7)
	{
		completos++;
		return;
	}

	//! Peça livre
	if(NAO_VISITADO(x, y))
	{
		int peca1 = tabuleiro[x][y];
 
		for(int i = 0; i < 2; i++)
		{
			int par_x = x +  (i); //! 0, 1
			int par_y = y + !(i); //! 1, 0

			if(DENTRO(par_x, 0, 7) && DENTRO(par_y, 0, 8) && NAO_VISITADO(par_x, par_y))
			{
				int peca2 = tabuleiro[par_x][par_y];

				if(dominos[peca1][peca2])
				{
					PEGA_PECA(peca1, peca2);
					
					VISITA(x, y, par_x, par_y);

					//! Ainda tem colunas livres?
					if(y < 7)
						aloca_domino(x, y + 1);
					
					//! Avança para a nova linha
					else
						aloca_domino(x + 1, 0);

					DESVISITA(x, y, par_x, par_y);

					DEVOLVE_PECA(peca1, peca2);
				}
			}
		}
	}

	//! Procura em outra posição
	else
	{
		//! Ainda tem colunas livres?
		if(y < 7)
			aloca_domino(x, y + 1);
		
		//! Avança para a nova linha
		else
			aloca_domino(x + 1, 0);
	}
}

int main()
{
	int casos;

	scanf("%d", &casos);

	for(int k = 0; k < casos; k++)
	{
		for(int i = 0; i < 7; i++)
			for(int j = 0; j < 8; j++)
				scanf("%d ", &tabuleiro[i][j]);

		completos = 0;
		aloca_domino(0, 0);

		printf("%d\n", completos);
	}
}