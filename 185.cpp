#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n,graph[100][100],flag[100];
bool fl=false;

void check()
{
	fl=true;
	for(int i=0; i<n; i++)
		if(flag[i]==0)
		{
			fl=false;
			break;
		}
}

void go(int row)
{
	flag[row]=1;
	for(int j=0; j<n; j++)
		if(graph[row][j]==1 && flag[j]==0)
		{
			go(j);
			check();
			
		}
	return;	
}
int main()
{
	int k,a,b;
	fin>>n>>k;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			graph[i][j]=0;
		flag[i]=0;
	}
	fin>>a;
	while(a!=0)
	{
		fin>>b;
		graph[a-1][b-1]=1;
		fin>>a;
	}
	go(k-1);
	check();
	if(fl) fout<<"Yes";
		else fout<<"No";
	
		
	
	return 0;
}
