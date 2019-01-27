#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n,m;
	fin>>n>>m;
	int graph[100][100],vector[100];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			graph[i][j]=30000;
			if(i==j) graph[i][j]=0;
			if(i==0) vector[j]=graph[i][j];
		}
	int a,b,weight;
	for(int i=0; i<m; i++)
	{
		fin>>a>>b>>weight;
		graph[a-1][b-1]=min(graph[a-1][b-1],weight);
	}
	bool flag;
	for(int p=0; p<n-1; p++)
	{
		flag=true;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(vector[i]<30000 && vector[j]>vector[i]+graph[i][j]) 
				{
					vector[j]=vector[i]+graph[i][j];
					flag=false;
				}
		if(flag) break;
	}


	for(int j=0; j<n; j++)
		fout<<vector[j]<<" ";
	return 0;			
}
