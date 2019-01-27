#include <fstream>
#include <iostream>
using namespace std;

long long factorial(long long N)
{
	if(N<0)
		return 0;
	else if(N==0)
		return 1;
	else return N*factorial(N-1);
}

long long combination(long long m, long long n)
{
	long long s=1;
	if(m>n-m)
	{
		for(int i=m+1; i<=n; i++)
			s*=i;
		s/=factorial(n-m);
	}
	else
	{
		for(int i=n-m+1; i<=n; i++)
			s*=i;
		s/=factorial(m);
	}
	return s;
}


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=1,k;
	fin>>n>>k;
	if(k>n)
		fout<<0;
	else
	{
		for(int i=0; i<k; i++)
			s*=(n-i);
		s*=combination(k,n);
		fout<<s;
	}
	return 0;
}
