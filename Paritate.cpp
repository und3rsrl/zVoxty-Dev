#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

ifstream in("paritate.in");
ofstream out("paritate.out");


vector<char> v;

int main()
{

	char c;
	int p = 1, lsb, nr = 0, ok = 0;
	char c_char = 0;
	while (in.get(c))
	{
		if (p % 8 == 1)
		{
			lsb = c - '0';
			nr = 0;
			c_char = 0;
		}
		else if (p % 8 == 0)
		{
			if (c - '0' == 1)
			{
				c_char |= 1 << (7 - (p - 1) % 8);
				++nr;
			}
			cout << (nr & 1);
			if (((lsb == 0 && ((nr & 1) == 0)) || (lsb == 1 && ((nr & 1) == 1))))
				v.push_back(c_char);
			else
			{
				if (!ok)
				{
					out << "NU\n" << p / 8 - 1 << ' ';
					ok = 1;
				}
				else
					out << p / 8 - 1 << " ";
			}
		}
		else
		{
			if (c - '0' == 1)
			{
				c_char |= 1 << (6 - (p - 2) % 8);
				++nr;
			}
		}
		++p;
	}
	if (!ok)
	{
		out << "DA\n";
		for (int i = 0; i < v.size(); ++i)
			out << v[i];
	}


	return 0;
}