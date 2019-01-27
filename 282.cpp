#include <fstream>
#include <iostream>
using namespace std;
 
long long fact(int N)
{
    if (N<0)
        return 0;
    else if(N==0)
        return 1;
    else
        return N*fact(N-1);
}
 
long long combination(int a, int b)
{
    long long q,p;
    if(b-a<a)
    {
        q=1,p=fact(b-a);
        for(int i=b; i>a; i--)
            q=q*i;  
    }
    else
    {
        q=1,p=fact(a);
        for(int i=b; i>b-a; i--)
            q=q*i;  
    }
    return q/p; 
}
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long m,n,s=0;
    fin>>n>>m;
    fout<<combination(2,n+1)*combination(2,m+1);
     
    return 0;
}
