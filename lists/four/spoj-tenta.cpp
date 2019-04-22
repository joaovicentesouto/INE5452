#include <stdio.h>
#include <string.h>

struct node
{
	long int v;
	struct node * left;
	struct node * right;
};

static int idx = 0;
static struct node nodes[8];
static struct node * root = NULL;

static struct node order[8];

struct node * insere(struct node * r, long int v)
{
	if (!r)
	{
		r = &nodes[idx++];
		r->v = v;
		return r;
	}

	if (v < r->v)
		r->left = insere(r->left, v);
	else
		r->right = insere(r->right, v);
	
	return r;
}

static int actual_i, total_n;

void percorre(struct node * r, int * i)
{
	if (!r)
		return;

	percorre(r->left, i);

	order[*i].v = r->v;

	if ((*i) > 0)
		order[*i].left = &order[(*i)-1];

	if ((*i) < total_n - 1)
		order[*i].right = &order[(*i)+1];

	(*i)++;

	percorre(r->right, i);
}

void build(long int numbers[8], struct node * begin, int nivel)
{
	if (!begin)
	{
		if (nivel == total_n)
		{
			for (int i = 0; i < (total_n - 1); i++)
				printf("%ld ", numbers[i]);
			printf("%ld\n", numbers[total_n-1]);
		}
		return;
	}

	for (struct node * i = begin; i != NULL; i = i->right)
	{
		numbers[nivel] = i->v;

		if (i->left)
			i->left->right = i->right;

		if (i->right)
			i->right->left = i->left;
		
		if (i == begin)
			build(numbers, i->right, nivel+1);
		else
			build(numbers, begin, nivel+1);

		if (i->left)
			i->left->right = i;

		if (i->right)
			i->right->left = i;
	}
}

int main(void)
{
	int n;
	long int aux;

	while (1)
	{
		scanf("%d", &n);

		if (!n)
			break;
		
		for (int i = 0; i < n; ++i)
		{
			scanf("%ld", &aux);
			root = insere(root, aux);
		}

		actual_i = 0;
		total_n = n;

		int k = 0;
		percorre(root, &k);

		long int numbers[8];
		build(numbers, &order[0], 0);

		memset(root, 0, 8 * sizeof(struct node));
		memset(order, 0, 8 * sizeof(struct node));
		root = NULL;
		idx = 0;

		printf("\n");
	}

	return 0;
}
