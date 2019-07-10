#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

const string EPR("EPR");
const string EHD("EHD");

int main()
{
	int n, m;
	char s[100];

    while(scanf("%d ", &n) != EOF)
    {
    	// unordered_map<int, bool> map;

    	int cepr = 0, cehd = 0, cintrusos = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		scanf("%d %s ", &m, &s);

    		string _s(s);

    		// if (!map[m])
    		// {
    		// 	map[m] = true;

    			if (EPR == _s)
    				cepr++;
    			else if (EHD == _s)
    				cehd++;
    			else
    				cintrusos++;
    		// }
    	}

    	printf("EPR: %d\nEHD: %d\nINTRUSOS: %d\n", cepr, cehd, cintrusos);
    }

	return 0;
}