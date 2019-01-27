#include <fstream>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int graph[1000][1000],flag[1000],n;
bool fl=false;


void dfs(int row)
{
	flag[row]=1;
	for(int j=0; j<n; j++)
	{
		if((graph[row][j]==1 && flag[j]==1) || fl)
		{
			fl=true;
			return;
		}
		if(graph[row][j]==1 && flag[j]!=1)
			dfs(j);
	}
	return;
}

void swap(int& a,int&  b)
{
	int c=a;
	a=b;
	b=c;
}
int main()
{
	int m,a,b;;
	fin>>n>>m;
	for(int i=0; i<n; i++)
	{
		flag[i]=0;
		for(int j=0; j<n; j++)
			graph[i][j]=0;
	}	
	for(int i=0; i<m; i++)
	{
		fin>>a>>b;
		if(b>a)	swap(a,b);
		graph[a-1][b-1]=1;
	}
	for(int i=0; i<n; i++)
	{
		if(fl) break;
		for(int j=0; j<n; j++)
			flag[j]=0;
		dfs(i);
	}
	if(fl) fout<<"YES";
		else fout<<"NO";
	return 0;
}
