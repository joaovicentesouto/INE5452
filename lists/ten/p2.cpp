#include <stdio.h>
#include <cmath>

using namespace std;

#define MAX 101

struct Point
{
	int x, y;
} points[MAX];

const double EPS = 1e-2;

int cmp(double x, double y)
{
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

int max(double a, double b)
{
	return (a > b) ? a : b;
}

bool conpute_center(const Point &p, const Point &q, const Point &r, Point &c)
{
	double ax = q.x - p.x;
	double ay = q.y - p.y;
	double bx = r.x - p.x;
	double by = r.y - p.y;

	double d = ax * by - bx * ay;

	if (cmp(d, 0) == 0)
		return false;

	double cx = (q.x + p.x) / 2;
	double cy = (q.y + p.y) / 2;
	double dx = (r.x + p.x) / 2;
	double dy = (r.y + p.y) / 2;

	double t1 = bx*dx + by*dy;
	double t2 = ax*cx + ay*cy;

	c.x = (by*t2 - ay*t1) / d;
	c.y = (ax*t1 - bx*t2) / d;

	return true;
}

double distance(const Point &a, const Point &b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main()
{
	int n, temp, max_cocircular_points;
	Point center;

	while (true)
	{
		scanf("%d ", &n);

		if (!n)
			break;

		for (int i = 0; i < n; ++i)
			scanf("%d %d ", &points[i].x, &points[i].y);

		if (n < 3)
		{
			printf("%d\n", n);
			continue;
		}

		max_cocircular_points = 2;

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
				{
					temp = 0;

					if (conpute_center(points[i], points[j], points[k], center))
					{
						double r = distance(center, points[i]);

						for (int m = 0; m < n; ++m)
						{
							if (cmp(r, distance(center, points[m])) == 0)
								temp++;
						}

						max_cocircular_points = max(max_cocircular_points, temp);
					}
				}
		
		
		printf("%d\n", max_cocircular_points);
	}

	return 0;
}
