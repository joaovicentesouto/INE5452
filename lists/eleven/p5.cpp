#include <stdio.h>

using namespace std;

const size_t ALPHABET_SIZE = 26;
const size_t NODE_MAX = 100001;

size_t _next = 0;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool is_end_of_word;
} _nodes[NODE_MAX];

struct TrieNode *get_node(void)
{
	struct TrieNode *node = &_nodes[_next++];

	node->is_end_of_word = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = NULL;

	return node;
}

bool insert(struct TrieNode *root, char *key)
{
	int index;
	bool new_word = true;
	struct TrieNode *crawl = root;

	for (; (*key) != '\0'; ++key)
	{
		index = (*key) - 'a';

		if (crawl->is_end_of_word)
			return false;

		new_word = !crawl->children[index];

		if (new_word)
			crawl->children[index] = get_node();

		crawl = crawl->children[index];
	}

	crawl->is_end_of_word = true;

	return new_word;
}

int main()
{
	int n;
	bool bad;
	char word[101];

	while (true)
	{
		scanf("%d ", &n);

		if (!n)
			break;
	
		_next = 0;
		bad = false;

		struct TrieNode *root = get_node();

		for (int i = 0; i < n; i++)
		{
			scanf("%s ", word);

			if (!bad)
				if (!insert(root, word))
					bad = true;
		}

		if (bad)
			printf("Conjunto Ruim\n");
		else
			printf("Conjunto Bom\n");
	}

	return 0;
}