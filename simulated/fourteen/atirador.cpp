#include <stdio.h>
#include <stdlib.h>

#define INF 16000000000000.111
#define DIF 0.000000001

typedef struct pt {
	int x;
	int y;
} Point;

inline double abs2(double a) {
	if (a < 0)
		return -a;
	return a;
}

inline int cmp(double a, double b) {
    if (abs2(a - b) < DIF) {
        return 0;
    } else if (a > b) {
        return 1;
    }
    return -1;
}

int compare (const void * a, const void * b)
{
    return cmp(*(double*)a, *(double*)b);
}

Point pontos[1000];
double coeficientes[1000];

int main() {
	int t;

	int n, i, j, k;
	int max;
	int fim;
	
	double difx, dify;
	int temp;
	double atual;

	scanf("%d", &t);

	for (;t>0;t--) {

		scanf("%d", &n);
		if (n == 1) {
			max = 1;
			scanf("%d %d", &pontos[0].x, &pontos[0].y);
			goto fim;
		}
		if (n == 2) {
			max = 2;
			scanf("%d %d", &pontos[0].x, &pontos[0].y);
			scanf("%d %d", &pontos[0].x, &pontos[0].y);
			goto fim;
		}

		for (i = 0; i < n; i++) {
			scanf("%d %d", &pontos[i].x, &pontos[i].y);
		}

		max = 0;
        //Para cada ponto i como pivô, descubro a maior quantidade de pontos colineares a ele
        i = 0;
		for (i = 0; i < n; i++) { 
			k = 0;
            //Calcula o coeficiente angular de todos os pontos em relação ao ponto i
			for (j = 0; j < n; j++) {
                if (j == i) continue;
                
				difx = pontos[i].x - pontos[j].x;
				dify = pontos[i].y - pontos[j].y;
				if (abs2(difx) < DIF) 
					coeficientes[k] = INF;
				else
					coeficientes[k] = dify / difx;	
				k++;				
			}

			//Ordena os coeficientes angulares
			qsort (&coeficientes[0], k, sizeof(double), compare);
			
            
            //Descubro a maior quantidade de pontos com o mesmo coeficiente angular
			for (j = 0;j < k;) {
				temp = 1; //Inicia com o próprio ponto i como parte da maior quantidade de pontos colineares
				atual = coeficientes[j];
				while (cmp(atual, coeficientes[j]) == 0) {
					temp++; j++;
					if (j >= k) break;
				}
				if (temp > max)
					max = temp;
			}
		}
fim:
		printf("%d\n", max);
	}

	return 0;
}

