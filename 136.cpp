#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int min(int a,int b)
{
	if(a<b) return a;
		else return b;
}

int main()
{
	int a[100][100],n;
	fin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin>>a[i][j];
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a[i][j]>-1 && a[i][k]>-1 && a[k][j]>-1)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				else if(a[i][k]>-1 && a[k][j]>-1)
					a[i][j]=a[i][k]+a[k][j];
	int max=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			if(a[i][j]>max) max=a[i][j];
	}
	fout<<max;
}
