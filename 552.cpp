#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=0,a[1000];
	fin>>n;
	if(n<3)
		fout<<0;
	else
	{
		for(int i=0; i<n; i++)
		fin>>a[i];
		long long sk[1000],sj[1000];
		sk[n-1]=a[n-1];
		for(int i=n-2; i>1; i--)
			sk[i]=a[i]+sk[i+1];
		sj[n-2]=a[n-2]*sk[n-1];
		for(int i=n-3; i>0; i--)
			sj[i]=a[i]*sk[i+1]+sj[i+1];
		for(int i=0; i+2<n; i++)
			s+=a[i]*sj[i+1];
		fout<<s;	
	}
	
	return 0;
}
