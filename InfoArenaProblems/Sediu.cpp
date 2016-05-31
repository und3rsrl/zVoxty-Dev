#include<fstream>
#include<iostream>
using namespace std;

#define MAX 16001

ifstream in("sediu.in");
ofstream out("sediu.out");

int N, T, i, j, x, y;

struct Node
{
	int v;
	Node *next;
}*A[MAX];

int D[MAX];
int S[MAX], st = 0;

void add_to_tree(int x, int y)
{
	Node *p = new Node;
	p->v = y;
	p->next = A[x];
	A[x] = p;
}

void DFS(int s, int p)
{
	Node *q = A[s];
	while (q)
	{
		if (q->v != p)
		{
			DFS(q->v, s);
			D[s] += D[q->v];
		}
		q = q->next;
	}
	++D[s];
}

int main()
{

	Node *q;
	int max;
	int min = 1 << 30;
	in >> N;
	for (j = 1; j <= N - 1; ++j)
	{
		in >> x >> y;
		add_to_tree(x, y);
		add_to_tree(y, x);
	}
	DFS(1, 0);
	for (j = 1; j <= N; ++j)
	{
		max = 0;
		q = A[j];
		while (q)
		{
			if (D[q->v] < D[j] && D[q->v]>max)
				max = D[q->v];
			if (D[q->v]>D[j] && (N - D[j])>max)
				max = N - D[j];
			q = q->next;
		}

		if (max < min)
		{
			min = max;
			st = 1;
			S[st] = j;
		}
		else if (max == min)
			S[++st] = j;

	}


	out << min << ' ' << st << '\n';

	for (i = 1; i <= st; ++i)
		out << S[i] << ' ';
	return 0;
}