#include <bits/stdc++.h>

using namespace std;
int n, a[3005];

int CautBin(int st, int dr, int x)
{
    int m;
    while(st<=dr)
    {
        m=(st+dr)/2;
        if(a[m]==x)return 1;
        if(a[m]<x)st=m+1;
        else dr=m-1;
    }
    return 0;
}

void Citire()
{
    int i;
    ifstream fin ("bete2.in");
    fin >> n;
    for(i=1; i<=n; i++)
        fin >> a[i];
    fin.close();

    sort(a+1,a+n+1);
}

void Rezolvare()
{
    ofstream fout("bete2.out");
    int i,j,sol=0,p;
    for(i=1; i<=n-2; i++)
        for(j=i+1; j<=n-1; j++)
           {
                p=CautBin(j+1,n,a[i]+a[j]);
                if(p==1)sol++;
           }
           fout << sol << "\n";
    fout.close();
}

int main()
{
    Citire();
    Rezolvare();

    return 0;
}
