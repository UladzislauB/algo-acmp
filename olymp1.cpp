#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n,m,a[500][500];
	unsigned long long elem,min,previous;
	fin>>n>>m;
	bool flag=false;
	unsigned long long first;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			fin>>elem;
			if(j==0 && i==0) 
			{
				first=elem;	
			}
			a[i][j]=elem-first;
		}
	unsigned long long sub1,sub2;
	for(int i=0; i<n; i++)
	{
		if(flag) break;
		
		for(int j=1; j<m; j++)
			if(j==1) sub1=a[i][j]-a[i][0];
				else 
			if(sub1!=a[i][j]-a[i][j-1])
			{
				flag=true;
				break;
			}
	}
	for(int i=1; i<n; i++)
	{
		if(flag) break;
		for(int j=0; j<m; j++)
			if(i==1) sub2=a[i][j]-a[0][j];
				else 
			if(sub2!=a[i][j]-a[i-1][j])
			{
				flag=true;
				break;
			}
	}
	if(!flag && a[0][1]*a[1][0]!=first)
		flag=true;
	if(flag) fout<<"false";
	else fout<<"true";
	return 0;
}
