#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using monte = pair<int, int>;

int main()
{
	int n{0}, jogadores{1};

	while(cin >> n >> jogadores)
	{
		int curr_jogador{0}, curr_carta{0};

		unordered_map<int, bool> descarte;
		vector<monte> montes(jogadores);

		if (!n && !jogadores)
			break;
		
		while (n--)
		{
			bool cont = false;

			cin >> curr_carta;

			if (descarte[curr_carta])
			{
				//! Pega descarte
				montes[curr_jogador].first   = curr_carta;
				montes[curr_jogador].second += 2;
				descarte[curr_carta] = false;

				continue;
			}

			for (auto i = 0; i < jogadores; ++i)
			{
				if (curr_jogador != i && montes[i].first == curr_carta)
				{
					//! Rouba monte
					montes[curr_jogador].first   = curr_carta;
					montes[curr_jogador].second += 1 + montes[i].second;

					//! Limpa monte
					montes[i].first  = 0;
					montes[i].second = 0;

					cont = true;
					break;
				}
			}

			if (cont)
				continue;
			
			if (montes[curr_jogador].first == curr_carta)
			{
				//! Pega carta atual;
				montes[curr_jogador].first = curr_carta;
				montes[curr_jogador].second++;

				continue;
			}

			//! Descarta carta
			descarte[curr_carta] = true;
			curr_jogador = (curr_jogador + 1) % jogadores;
		}

		unordered_map<int, vector<int>> biggers;
		int size = -1;
		for (auto i = 0; i < jogadores; ++i)
		{
			if (size <= montes[i].second)
			{
				size = montes[i].second;
				biggers[size];
				biggers[size].push_back(i);
			}
		}

		cout << size;
		for (auto i : biggers[size])
			cout << " " << i+1;
		cout << endl;
	}

	return 0;
}