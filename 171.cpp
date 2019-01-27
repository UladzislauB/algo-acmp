#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long s[1002],i,n,div=2,sum=1;
	fin>>n;
	if(n==1) fout<<1;
	else 
	{
		for(int i=0; i<1002; i++)
			s[i]=0;
		while(n>1)
		{
			while(n%div==0)
			{
				s[div-1]++;
				n/=div;
			}
			div++;
		}
		for(int i=0; i<1002; i++)
			if(s[i]!=0) sum*=(s[i]+1);
		if(sum==1) fout<<2;
		else fout<<sum;	
	}
	return 0;

}
