#include<fstream>
#include<vector>
using namespace std;

#define MAX 100001

ifstream in("posta2.in");
ofstream out("posta2.out");


struct Node
{
	int v;
	int c;
	Node *next;
}*A[MAX];

long long  D[MAX];

int  P[MAX], NR[MAX], O[MAX], F[MAX];


int N, M, i, j, x, y, c, T;

void add_to_tree(int x, int y, int c)
{
	Node *p = new Node;
	p->v = y;
	p->c = c;
	p->next = A[x];
	A[x] = p;
}

void DFS1(int s, int p)
{
	Node *q = A[s];
	while (q)
	{
		if (q->v != p)
		{
			DFS1(q->v, s);

			if (NR[q->v] >= 1)
				D[s] += NR[q->v] * P[q->v];

			if (O[q->v])
			{
				if (!NR[q->v])
				{
					++NR[q->v];
					F[q->v] = 1;
				}
			}
			if (NR[q->v])
			{
				D[s] += D[q->v] + 2 * q->c;
				NR[s] += 1;
			}
		}
		q = q->next;
	}
}

void DFS2(int s, int p)
{
	Node *q = A[s];
	while (q)
	{
		if (q->v != p)
		{
			if (NR[q->v])
			{
				D[q->v] = D[s] - 2 * q->c - P[q->v] * (NR[q->v]);
				if (F[q->v])
					D[q->v] += P[q->v] * (NR[q->v]);
			}
			else
				D[q->v] = D[s];
			if (NR[s] - 1 == 0)
			{
				if (O[s])
				{
					D[q->v] += 2 * q->c;
					++NR[q->v];
				}
			}
			else
			{
				D[q->v] += 2 * q->c + P[s] * (NR[s] - 1);
				++NR[q->v];
			}

			DFS2(q->v, s);
		}
		q = q->next;
	}
}
int main()
{

	in >> N >> M;

	for (i = 1; i <= N - 1; ++i)
	{
		in >> x >> y >> c;
		add_to_tree(x, y, c);
		add_to_tree(y, x, c);
	}
	for (i = 1; i <= N; ++i)
		in >> P[i];

	for (i = 1; i <= M; ++i)
	{
		in >> x;
		O[x] = 1;
	}
	DFS1(1, 0);

	DFS2(1, 0);
	/*
	for (i = 1; i <= N; ++i)
	out << D[i] << " ";
	out << '\n';*/
	long long min = D[1];
	for (i = 2; i <= N; ++i)
		if (D[i] < min)
			min = D[i];
	out << min;



	return 0;
}