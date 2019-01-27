#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

unsigned long long fact(unsigned long long N)
{
	if(N<0)
		return 0;
	else if(N==0)
		return 1;
	else return N*fact(N-1);
}

unsigned long long combination(unsigned long long m, unsigned long long n)
{
	unsigned long long c=1;
	if(n-m>m)
	{
		for(int i=n-m+1; i<=n; i++)
			c*=i;
		c/=fact(m);
	}
	else
	{
		for(int i=m+1; i<=n; i++)
			c*=i;
		c/=fact(n-m);
	}
	return c;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char s[34];
	fin.getline(s,34);
	unsigned long long l=strlen(s),m,n,s=0;
	for(int i=m; i<=n; i++)
		s+=combination(i,n);
	fout<<s;
	return 0;
}
