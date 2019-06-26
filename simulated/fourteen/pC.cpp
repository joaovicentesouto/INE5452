#include <stdio.h>
#include <math.h>

#define DIF 0.000000001

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

int main()
{
	int n, h, c, l;

    while (scanf("%d ", &n) != EOF)
    {
    	scanf("%d %d %d ", &h, &c, &l);

    	double resp = l * sqrt(c * c + h * h) * n;

	    printf("%.4f\n", resp / 10000);
	}

    return 0;
}
