// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cmath>

#define MAX 2001

using namespace std;

struct Point
{
	int x, y;
};

double distance(const Point & a, const Point & b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Point p0;

Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0; // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *) vp1;
	Point *p2 = (Point *) vp2;

	int o = orientation(p0, *p1, *p2);

	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}

double convexHull(Point points[], int n)
{
	int ymin = points[0].y, min = 0;

	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	swap(points[0], points[min]);

	p0 = points[0];
	qsort(&points[1], n-1, sizeof(Point), compare);

	int m = 1;

	for (int i = 1; i < n; i++)
	{
		while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
			i++;


		points[m] = points[i];
		m++;
	}

	if (m < 3)
		return 0;

	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	for (int i = 3; i < m; i++)
	{
		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();

		S.push(points[i]);
	}

	double answer = 0;
	Point first, curr, prev;
	
	curr = first = S.top();
	S.pop();

	while (!S.empty())
	{
		prev = curr;
		curr = S.top();
		S.pop();

		answer += distance(prev, curr);
	}

	answer += distance(curr, first);

	return answer;
}

Point points[MAX];

// Driver program to test above functions
int main()
{
	int n;

	while (true)
	{
		scanf("%d ", &n);

		if (!n)
			break;

		for (int i = 0; i < n; ++i)
			scanf("%d %d ", &points[i].x, &points[i].y);

		printf("Tera que comprar uma fita de tamanho %.2f.\n", convexHull(points, n));
	}
	return 0;
}
