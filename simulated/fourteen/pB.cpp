#include<stdio.h>

typedef struct pto2D
{
    int x;
    int y;
} Ponto2D;

typedef struct quad
{
    Ponto2D superior;
    Ponto2D inferior;
} Quad2D;


inline Ponto2D superior(Ponto2D &a, Ponto2D &b)
{
	return {
		a.x < b.x ? b.x : a.x,
		a.y > b.y ? b.y : a.y,
	}; 
}

inline Ponto2D inferior(Ponto2D &a, Ponto2D &b)
{
	return {
		a.x > b.x ? b.x : a.x,
		a.y < b.y ? b.y : a.y,
	}; 
}

inline Quad2D intersection(Quad2D &a, Quad2D &b)
{
	return {
		superior(a.superior, b.superior),
		inferior(a.inferior, b.inferior)
	};
}

int main() {
	int n;
    Quad2D a, b, temp;

    int cases = 1;

    while (true)
    {
    	scanf("%d ", &n);

    	if (!n)
    		break;

    	scanf("%d %d %d %d ",
    		&a.superior.x,
    		&a.superior.y,
    		&a.inferior.x,
    		&a.inferior.y
		);

		bool error = false;

		for (int i = 0; i < n-1; i++)
		{
	    	scanf("%d %d %d %d ",
	    		&b.superior.x,
	    		&b.superior.y,
	    		&b.inferior.x,
	    		&b.inferior.y
			);

			if (error)
				continue;

			a = intersection(a, b);

			if (a.superior.x >= a.inferior.x || a.superior.y <= a.inferior.y)
				error = true;
		}

		if (error)
			printf("Teste %d\nnenhum\n\n", cases++);		
		else
			printf("Teste %d\n%d %d %d %d\n\n",
				cases++,
				a.superior.x,
				a.superior.y,
				a.inferior.x,
				a.inferior.y
			);
    }

    return 0;
}
