#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

const long long int ARRAY_MAX_SIZE = 1000001;

long long int tree[ARRAY_MAX_SIZE] = {0}; // To store segment tree 
long long int lazy[ARRAY_MAX_SIZE] = {0}; // To store pending updates 

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void aux_update_range(int si, int ss, int se, int us, int ue, long long int diff) 
{ 
	if (lazy[si] != 0) 
	{
		tree[si] += (se-ss+1)*lazy[si]; 

		if (ss != se) 
		{ 
			lazy[si*2 + 1] += lazy[si]; 
			lazy[si*2 + 2] += lazy[si]; 
		} 

		lazy[si] = 0; 
	} 

	if (ss > se || ss > ue || se < us) 
		return;

	if (ss >= us && se <= ue) 
	{ 
		tree[si] += (se-ss+1)*diff; 

		if (ss != se) 
		{
			lazy[si*2 + 1] += diff; 
			lazy[si*2 + 2] += diff; 
		}

		return; 
	} 

	int mid = (ss + se) / 2;

	aux_update_range(si*2+1, ss, mid, us, ue, diff); 
	aux_update_range(si*2+2, mid+1, se, us, ue, diff); 

	tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 

void update_range(int n, int us, int ue, int diff) 
{ 
	aux_update_range(0, 0, n-1, us, ue, diff); 
} 

long long int aux_get_sum(int ss, int se, int qs, int qe, int si) 
{ 
	if (lazy[si] != 0) 
	{
		tree[si] += (se-ss+1)*lazy[si]; 

		if (ss != se) 
		{ 
			lazy[si*2+1] += lazy[si]; 
			lazy[si*2+2] += lazy[si]; 
		} 

		lazy[si] = 0; 
	} 

	if (ss > se || ss > qe || se < qs) 
		return 0; 

	if (ss >= qs && se <= qe) 
		return tree[si]; 

	int mid = (ss + se) / 2;
 
	return aux_get_sum(   ss, mid, qs, qe, 2*si+1)
	     + aux_get_sum(mid+1,  se, qs, qe, 2*si+2); 
} 

long long int get_sum(int n, int qs, int qe) 
{ 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		printf("Invalid Input"); 
		return -1; 
	} 

	return aux_get_sum(0, n-1, qs, qe, 0); 
} 

void aux_construct_st(int ss, int se, int si) 
{ 
	if (ss > se) 
		return; 

	if (ss == se) 
	{ 
		tree[si] = 0;
		lazy[si] = 0;
		return;
	} 

	int mid = (ss + se) / 2; 

	aux_construct_st(ss, mid, si*2+1); 
	aux_construct_st(mid+1, se, si*2+2); 

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
	lazy[si] = 0;
}

void construct_st(int n) 
{ 
	aux_construct_st(0, n-1, 0); 
}

int main()
{
	int cases;

	int n, c, op, p, q, v, inf, sup;

	scanf("%d ", &cases);

	while (cases--)
	{
		scanf("%d %d ", &n, &c);

		construct_st(n);

		for (int k = 0; k < c; k++)
		{
			scanf("%d %d %d ", &op, &p, &q);

			inf = min(p-1, q-1);
			sup = max(p-1, q-1);

			if (op == 0)
			{
				scanf("%d ", &v);
				update_range(n, inf, sup, v);
			}
			else
				printf("%lld\n", get_sum(n, inf, sup));
		}
	}

	return 0;
}