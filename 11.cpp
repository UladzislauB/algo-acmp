#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int* add(int* a,int& l1,int* b,int& l2)
{
	int temp;
	if(l1>l2) l1++;
	else l1=l2+1;
	for(int i=1; i<=l2; i++)
	{
		temp=a[i]+b[i];
		a[i]=temp%10;
		a[i+1]=a[i+1]+temp/10;
	}
	if(a[l1]==0) l1--;
	return a;
}

int main()
{
	int** a=new int* [310];
	for(int i=0; i<310; i++)
		a[i]=new int [301];
	for(int i=0; i<310; i++)
	{
		a[i][0]=1;
		for(int j=1; j<=301; j++)
			a[i][j]=0;
	}
	a[0][1]=1;
	int n,k;
	fin>>k>>n;
	for(int i=1; i<=n; i++)
		for(int j=i-k; j<i; j++)
			if(j>=0) a[i]=add(a[i],a[i][0],a[j],a[j][0]);	
	for(int i=a[n][0]; i>0; i--)
		fout<<a[n][i];
	
	return 0;
}
