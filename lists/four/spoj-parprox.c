#include <stdio.h>
#include <string.h>
#include <math.h>

struct node {
	double x, y;
};

double dist(struct node * a, struct node * b) 
{
    return sqrt(
        pow(a->x - b->x, 2) + 
        pow(a->y - b->y, 2)
    );
}

int main(void)
{
	int n;
	int x, y;

    struct node nodes[1000];

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &x, &y);
        nodes[i].x = x;
        nodes[i].y = y;
    }

    double menor_d = dist(&nodes[0], &nodes[1]);

    for (int i =   0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
    {
        double d = dist(&nodes[i], &nodes[j]);

        if (d < menor_d)
            menor_d = d;
    }

    printf("%.3f\n", menor_d);

	return 0;
}
