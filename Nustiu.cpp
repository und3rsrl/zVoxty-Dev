#include<fstream>
#include<iostream>
using namespace std;

#define MAX 10001

ifstream in("nustiu.in");
ofstream out("nustiu.out");

int N, T, i, j, x, y, ok, ok_temp;

struct Node
{
	int v;
	Node *next;
}*A[10][MAX];

int D[10][MAX];

void add_to_tree(int t, int x, int y)
{
	Node *p = new Node;
	p->v = y;
	p->next = A[t][x];
	A[t][x] = p;
}

void DFS(int t, int s, int p)
{
	Node *q = A[t][s];
	while (q)
	{
		if (q->v != p)
		{
			DFS(t, q->v, s);
			D[t][s] += D[t][q->v];
		}
		q = q->next;
	}
	D[t][s] += 1;
}

int main()
{

	in >> T;
	Node *q;
	for (i = 0; i < T; ++i)
	{
		ok = 0;
		in >> N;
		for (j = 1; j <= N - 1; ++j)
		{
			in >> x >> y;
			add_to_tree(i, x, y);
			add_to_tree(i, y, x);
		}
		DFS(i, 1, 0);
		for (j = 1; j <= N && N != 1; ++j)
		{
			q = A[i][j];
			ok_temp = 1;
			while (q)
			{
				if ((D[i][q->v]<D[i][j] && D[i][q->v]>N / 2) || (D[i][q->v]>D[i][j] && (N - D[i][j]) > N / 2))
					ok_temp = 0;
				q = q->next;
			}
			if (ok_temp)
			{
				out << j << '\n';
				ok = 1;
			}
		}
		if (!ok)
			out << "NIMIC\n";
	}

	return 0;
}