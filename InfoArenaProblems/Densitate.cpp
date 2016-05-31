#include<fstream>
using namespace std;
int v[500001], N, Q, i, j, a, b;
ifstream in("densitate.in");
ofstream out("densitate.out");
int main()
{
	in >> N >> Q;
	for (i = 2; i <= N; ++i)
	{
		if (v[i] == 0)
			for (j = i; j <= N / i; ++j)
				v[j*i] = 1;
		v[i] = v[i - 1] + (v[i] == 0);
	}
	for (i = 1; i <= Q; ++i)
	{
		in >> a >> b;
		out << v[b] - v[a - 1] << '\n';
	}

	return 0;
}