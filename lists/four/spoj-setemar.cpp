#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MOVE(tx, ty, ch) (tabuleiro[tx][ty] = ch)

//! Variáveis globais
vector<pair<int, int>> inimigos;
pair<int, int> jogador;
char tabuleiro[9][8];

bool destroi_inimigos(int nivel)
{
    if (nivel == 10 && inimigos.empty())
        return true;

    if (nivel == 10)
        return false; //! Não consegui matar

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0
             || i == -1 && jogador.first  == 0
             || i ==  1 && jogador.first  == 8
             || j == -1 && jogador.second == 0
             || j ==  1 && jogador.second == 7
            )
                continue;

            bool morte = false;

            pair<int, int> antigo_jogador = jogador;
            vector<pair<int, int>> antigos_inimigos(inimigos.begin(), inimigos.end());
            unordered_map<int, int> olds;

            inimigos.clear();
            jogador = {jogador.first + i, jogador.second + j};


            if (tabuleiro[jogador.first][jogador.second] == 'E' || tabuleiro[jogador.first][jogador.second] == '#')
            {
                morte = true;
                goto morte_label;
            }

            MOVE(antigo_jogador.first, antigo_jogador.second, '.');
            MOVE(jogador.first, jogador.second, 'S');
            
            for (auto i : antigos_inimigos)
            {
                int ix =  i.first  + (jogador.first  < i.first  ? -1 : jogador.first  > i.first  ? 1 : 0);
                int iy =  i.second + (jogador.second < i.second ? -1 : jogador.second > i.second ? 1 : 0);

                if (tabuleiro[ix][iy] == '.')
                {
                    inimigos.push_back({ix, iy});
                    olds[ix * 100 + iy] = i.first * 100 + i.second;
                    MOVE(i.first, i.second, '.');
                    MOVE(ix, iy, 'E');
                }
                else if (tabuleiro[ix][iy] == 'S')
                {
                    morte = true;
                    break;
                }
            }

            if (!morte)
                if (destroi_inimigos(nivel + 1))
                    return true;
            
            for (auto p : olds)
            {
                MOVE(p.first/100, p.first%10, '.');
                MOVE(p.second/100, p.second%10, 'E');
            }
            MOVE(jogador.first, jogador.second, '.');
            MOVE(antigo_jogador.first, antigo_jogador.second, 'S');
morte_label:
            jogador = antigo_jogador;
            inimigos = antigos_inimigos;
        }
    }

    return false;
}

int main(void)
{
    int casos;

    cin >> casos;

    for (int c = 0; c < casos; c++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> tabuleiro[i][j];
                if (tabuleiro[i][j] == 'S')
                    jogador = {i, j};
                else if (tabuleiro[i][j] == 'E')
                    inimigos.push_back({i, j});
            }
        }
        
        if (destroi_inimigos(0))
            cout << "I'm the king of the Seven Seas!" << endl;
        else
            cout << "Oh no! I'm a dead man!" << endl;
        
        inimigos.clear();
    }
}