#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

const size_t ARRAY_MAX_SIZE = 100001;

int _array[ARRAY_MAX_SIZE];
int _relative[ARRAY_MAX_SIZE];

struct Node
{
	long long int monsters;
};

int get_middle(int s, int e)
{
	return s + (e -s)/2;
}

struct Node aux_monsters(struct Node *st, int ss, int se, int qs, int qe, int index)
{
	struct Node left, right;

	if (qs <= ss && qe >= se)
		return st[index];

	if (se < qs || ss > qe)
		return {0ULL};

	int mid = get_middle(ss, se);

	left  = aux_monsters(st,    ss, mid, qs, qe, 2*index+1);
	right = aux_monsters(st, mid+1,  se, qs, qe, 2*index+2);

	return {left.monsters | right.monsters};
}

struct Node monsters(struct Node *st, int n, int qs, int qe)
{
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		printf("Invalid Input");
		return {0};
	}

	return aux_monsters(st, 0, n-1, qs, qe, 0);
}

void aux_update_value(struct Node *st, int ss, int se, int i, int new_type, int si)
{
	if (i < ss || i > se)
		return;

	if (se != ss)
	{
		int mid = get_middle(ss, se);
		aux_update_value(st,    ss, mid, i, new_type, 2*si+1);
		aux_update_value(st, mid+1,  se, i, new_type, 2*si+2);

		st[si].monsters = 0ULL;
		st[si].monsters = st[si*2+1].monsters | st[si*2+2].monsters;
	}
}

void update_value(int arr[], struct Node *st, int n, int i, int new_type)
{
	if (i < 0 || i > n-1)
		return; //! Invalid

	arr[i] = new_type;

	st[_relative[i]].monsters = 0ULL;
	st[_relative[i]].monsters = 1ULL << new_type;

	aux_update_value(st, 0, n-1, i, new_type, 0);
}

void construct_st(int arr[], int ss, int se, struct Node *st, int si)
{
	if (ss == se)
	{
		st[si].monsters = 0ULL;
		st[si].monsters = 1ULL << arr[ss];
		_relative[ss] = si;

		return;
	}

	int mid = get_middle(ss, se);

	construct_st(arr, ss, mid, st, si*2+1);
	construct_st(arr, mid+1, se, st, si*2+2);

	st[si].monsters = 0ULL;
	st[si].monsters = st[si*2+1].monsters | st[si*2+2].monsters;
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
	int n, q, m, type, op, l, r;
	int *segtree;
	char word[101];

	while (scanf("%d %d %d ", &n, &q, &m) != EOF)
	{
		for (int k = 0; k < n; k++)
		{
			scanf("%d ", &type);

			_array[k] = type;
		}

		struct Node *st = construct_st(_array, n);

		for (int k = 0; k < q; k++)
		{
			scanf("%d %d %d", &op, &l, &r);

			if (op == 2)
				update_value(_array, st, n, l-1, r);
			else
			{
				long long int value = monsters(st, n, l-1, r-1).monsters;

				int count = 0;
				for (int x = 0; x < 50; ++x)
				{
					if (value & (1ULL << x))
						count++;
				}

				printf("%d\n", count);
			}
		}

		destroy_st(st);
	}

	return 0;
}