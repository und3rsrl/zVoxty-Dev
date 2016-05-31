#include<fstream>
#include<vector>
using namespace std;
ifstream in("thread.in");
ofstream out("thread.out");
int V[70000];
vector<int> a;
int main() {
 
   int T,N,x,k,i,j,l,nr=0;
 
   in>>T;
   for(i=1;i<=T;++i)
   {
       nr=0;
       in>>N;
       for(j=1;j<=N;++j)
       {
         in>>x;
         l=a.size();
         if(V[x]<i)
         {
            V[x]=i;
            a.push_back(x);
            ++nr;
         }
         for(k=0;k<l;++k)
             if(V[a[k]+x]<i)
             {
                V[a[k]+x]=i;
                 a.push_back(a[k]+x);
                 ++nr;
 
             }
       }
       out<<nr<<'\n';
       a.clear();
   }
 
    return 0;
}