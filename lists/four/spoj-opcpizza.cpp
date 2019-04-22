#include <stdio.h>
#include <string.h>

#include <unordered_map>

using namespace std;

int main(void)
{
	int n;
	int aux;

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
    {
        int m, preco;
        scanf("%d %d", &m, &preco);

        std::unordered_map<int, int> map;

        int pares = 0;
        for (int j = 0; (j < m) && (pares < m/2); j++)
        {
            int aux;
            scanf("%d", &aux);

            if (map[preco - aux])
            {
                pares++;
                map[preco - aux]--;
            }
            else
                map[aux]++;
        }

        printf("%d\n", pares);
    }

	return 0;
}
