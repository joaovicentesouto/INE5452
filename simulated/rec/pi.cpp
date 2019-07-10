#include <stdio.h>
#include <queue>

using namespace std;

int count, top;
int F, R, K;

queue<int> q1;
queue<int> q2;
bool tape[100010] = { 0 };

int main ()
{
	scanf("%d %d ", &F, &R);

	tape[0] = true;
	tape[F+1] = true;

	for (int i = 0; i < R; ++i)
	{
		scanf("%d ", &K);

		q1.push(K);
		tape[K] = true;
	}

	count = 0;

	queue<int> *curr_q = &q1;
	queue<int> *next_q = &q2;

	while (!curr_q->empty() && count < F)
	{
		while (!curr_q->empty())
		{
			top = curr_q->front();
			curr_q->pop();
			
			if (!tape[top-1])
			{
				tape[top-1] = true;
				next_q->push(top-1);
			}


			if (!tape[top+1])
			{
				tape[top+1] = true;
				next_q->push(top+1);
			}
		}


		count++;

		queue<int> * tmp = curr_q;
		curr_q = next_q;
		next_q = tmp;
	}

	printf("%d\n", count-1);

	return 0;
}