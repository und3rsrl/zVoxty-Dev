#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	int u;
	int h = 0;
	int m = 0;
	cin>>u;
	while (u--)
	{
		h = (u * 2) / 60;
		m = (u * 2) % 60;

		h = (9 + h) % 12;

		if (h < 10)
			cout << '0' << h << ':';
		else
			cout << h << ':';
		if (m < 10)
			cout << '0' << m;
		else
			cout << m;

		cout << '\n';
	}


	return 0;
}
