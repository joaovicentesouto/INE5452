#include<stdio.h>

#define DIF 0.000000001

typedef struct Ponto {
    double x;
    double y;
} Ponto2D;

inline double abs2(double a) {
	if (a < 0)
		return -a;
	return a;
}

inline int abs3(int a) {
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

inline int cmp2(int a, int b) {
    if (abs2(a - b) < DIF) {
        return 0;
    } else if (a > b) {
        return 1;
    }
    return -1;
}

inline double area_quadrilatero(Ponto &a, Ponto &b, Ponto &c, Ponto &d)
{
	Ponto centro = {(a.x + b.x + c.x + d.x)/4, (a.y + b.y + c.y + d.y)/4 };

	Ponto lb, lu, rb, ru;

	if (a.x < centro.x && a.y < centro.y)
		lb = a;
	else if (b.x < centro.x && b.y < centro.y)
		lb = b;
	else if (c.x < centro.x && c.y < centro.y)
		lb = c;
	else if (d.x < centro.x && d.y < centro.y)
		lb = d;

	if (a.x < centro.x && a.y > centro.y)
		lu = a;
	else if (b.x < centro.x && b.y > centro.y)
		lu = b;
	else if (c.x < centro.x && c.y > centro.y)
		lu = c;
	else if (d.x < centro.x && d.y > centro.y)
		lu = d;

	if (a.x > centro.x && a.y < centro.y)
		rb = a;
	else if (b.x > centro.x && b.y < centro.y)
		rb = b;
	else if (c.x > centro.x && c.y < centro.y)
		rb = c;
	else if (d.x > centro.x && d.y < centro.y)
		rb = d;

	if (a.x > centro.x && a.y > centro.y)
		ru = a;
	else if (b.x > centro.x && b.y > centro.y)
		ru = b;
	else if (c.x > centro.x && c.y > centro.y)
		ru = c;
	else if (d.x > centro.x && d.y > centro.y)
		ru = d;

	return 1.0 / 2.0 * (
		abs2(
			lb.x * (lu.y - rb.y) + 
			lu.x * (ru.y - lb.y) +
			ru.x * (rb.y - lu.y) +
			rb.x * (lb.y - ru.y)
		)
	);
}

int main() {
	int resp, temp;
    Ponto a, b, c, d, e;
    int ax, ay, bx, by, cx, cy, dx, dy, ex, ey;

    while (true)
    {
	    scanf("%d %d  %d %d  %d %d  %d %d  %d %d ",
	    	&ax, &ay,
	    	&bx, &by,
	    	&cx, &cy,
	    	&dx, &dy,
	    	&ex, &ey
	    );

	    a.x = ax; a.y = ay;
    	b.x = bx; b.y = by;
    	c.x = cx; c.y = cy;
    	d.x = dx; d.y = dy;
    	e.x = ex; e.y = ey;

	    if ((a.x + a.y + b.x + b.y + c.x + c.y + d.x + d.y + e.x + e.y) == 0)
	    	break;


	    resp = area_quadrilatero(a, b, c, d);
	    temp = area_quadrilatero(a, b, c, e);

	    Ponto esq, dir, cima, baixo;

		printf("A %f\n", area_quadrilatero(a, b, c, d));
		printf("A %f\n", area_quadrilatero(b, a, c, d));
		printf("A %f\n", area_quadrilatero(b, a, d, c));
		printf("A %f\n", area_quadrilatero(c, d, a, b));

		printf("%d\n", temp);

	    if (cmp2(resp, temp) == -1)
	    	resp = temp;

		printf("%d\n", temp);

	    temp = area_quadrilatero(a, b, d, e);

		if (cmp2(resp, temp) == -1)
			resp = temp;

		printf("%d\n", temp);

	    temp = area_quadrilatero(a, c, d, e);

		if (cmp2(resp, temp) == -1)
			resp = temp;

		printf("%d\n", temp);

	    temp = area_quadrilatero(b, c, d, e);

		if (cmp2(resp, temp) == -1)
			resp = temp;

		printf("%d\n", (int) resp);
    }

    return 0;
}
