#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

const size_t ARRAY_MAX_SIZE = 100001;

int _array[ARRAY_MAX_SIZE];
int _relative[ARRAY_MAX_SIZE];

struct Node
{
	int min;
	int max;
};

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int get_middle(int s, int e)
{
	return s + (e -s)/2;
}

struct Node aux_max_min(struct Node *st, int ss, int se, int qs, int qe, int index)
{
	struct Node tmp, left, right;

	if (qs <= ss && qe >= se)
		return st[index];

	if (se < qs || ss > qe)
	{
		tmp.min = INT_MAX;
		tmp.max = INT_MIN;

		return tmp;
	}

	int mid = get_middle(ss, se);

	left  = aux_max_min(st, ss, mid, qs, qe, 2*index+1);
	right = aux_max_min(st, mid+1, se, qs, qe, 2*index+2);

	tmp.min = min(left.min, right.min);
	tmp.max = max(left.max, right.max);

	return tmp;
}

struct Node max_min(struct Node *st, int n, int qs, int qe)
{
	struct Node tmp;

	if (qs < 0 || qe > n-1 || qs > qe)
	{
		printf("Invalid Input");

		tmp.min = INT_MIN;
		tmp.min = INT_MAX;

		return tmp;
	}

	return aux_max_min(st, 0, n-1, qs, qe, 0);
}

void aux_update_value(struct Node *st, int ss, int se, int i, int new_val, int si)
{
	if (i < ss || i > se)
		return;

	if (se != ss)
	{
		int mid = get_middle(ss, se);
		aux_update_value(st,    ss, mid, i, new_val, 2*si+1);
		aux_update_value(st, mid+1,  se, i, new_val, 2*si+2);

		st[si].min = min(st[si*2+1].min, st[si*2+2].min);
		st[si].max = max(st[si*2+1].max, st[si*2+2].max);
	}
}

void update_value(int arr[], struct Node *st, int n, int i, int new_val)
{
	if (i < 0 || i > n-1)
		return; //! Invalid

	st[_relative[i]].min = new_val;
	st[_relative[i]].max = new_val;

	arr[i] = new_val;

	aux_update_value(st, 0, n-1, i, new_val, 0);
}

void construct_st(int arr[], int ss, int se, struct Node *st, int si)
{
	if (ss == se)
	{
		st[si].min = arr[ss];
		st[si].max = arr[ss];
		_relative[ss] = si;

		return;
	}

	int mid = get_middle(ss, se);

	construct_st(arr, ss, mid, st, si*2+1);
	construct_st(arr, mid+1, se, st, si*2+2);

	st[si].min = min(st[si*2+1].min, st[si*2+2].min);
	st[si].max = max(st[si*2+1].max, st[si*2+2].max);
}

struct Node *construct_st(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));

	int max_size = 2*(int)pow(2, x) - 1;

	struct Node *st = new struct Node[max_size];

	construct_st(arr, 0, n-1, st, 0);

	return st;
}

void destroy_st(struct Node * st)
{
	delete st;
}

int main()
{
	int n, p, q, op, i, j;
	int *segtree;
	char word[101];

	while (scanf("%d ", &n) != EOF)
	{
		for (int k = 0; k < n; k++)
		{
			scanf("%d ", &p);

			_array[k] = p;
		}

		struct Node *st = construct_st(_array, n);

		scanf("%d ", &q);

		for (int k = 0; k < q; k++)
		{
			scanf("%d %d %d", &op, &i, &j);

			if (op == 1)
				update_value(_array, st, n, i-1, j);
			else
			{
				struct Node nodet = max_min(st, n, i-1, j-1);
				printf("%d\n", nodet.max - nodet.min);
			}
		}

		destroy_st(st);
	}

	return 0;
}