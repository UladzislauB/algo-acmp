#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int min (int a,int b)
{
	if (a<b)
		return a;
	else return b;
}

int main()
{
	int n;
	fin>>n;
	int graph[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin>>graph[i][j];
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			fout<<graph[i][j]<<" ";
		fout<<endl;	
	}
	return 0;
}
