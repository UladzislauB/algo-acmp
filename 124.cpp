#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int array[100][100],counter[100],x,y,m,n,s=0;
	fin>>n>>m;
	for(int i=0; i<n; i++)
	{
		counter[i]=0;
		for(int j=0; j<n; j++)
			array[i][j]=0;
	}
	for(int i=0; i<m; i++)
	{
		fin>>x>>y;
		if(array[x-1][y-1]!=1)
		{
			array[x-1][y-1]=array[y-1][x-1]=1;
			counter[x-1]++;
			counter[y-1]++;
		}
	}
	for(int i=0; i<n; i++)
		fout<<counter[i]<<" ";
	return 0;
}
