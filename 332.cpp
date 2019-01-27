#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n,a[251][251],d[251];
bool u[251];

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int main()
{
	fin>>n;

	for	(int i=0; i<n+1; i++)
	{	
		d[i]=10000;
		u[i]=false;
		for(int j=0; j<n+1; j++)
			if(j<i) a[i][j]=10000;
			else if(i==j) a[i][j]=0;
			else
			{
				fin>>a[i][j];	
			}
	}
	d[0]=0;
	
	for(int i=0; i<n+1; i++)
	{
		int min_path=10000,curent;
		for(int j=0; j<n+1; j++)
			if(d[j]<min_path && u[j]==false) 
			{
				min_path=d[j];
				curent=j;
			}
		u[curent]=true;
		for(int j=0; j<n+1; j++)
			d[j]=min(d[j],a[curent][j]+d[curent]);
	}
	fout<<d[n];
	return 0;
}
