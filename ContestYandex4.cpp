#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a[100][100],b[100][100],c[100][100],n,m;
bool old_is_a=true;


int check_on_stability(int x,int y)
{
	int sum=0;
	if(old_is_a)
	{
		if(x-1>=0)
			if(a[x-1][y]==2) sum++;
		if(x+1<n)
			if(a[x+1][y]==2) sum++;
		if(y-1>=0)
			if(a[x][y-1]==2) sum++;
		if(y+1<m)
			if(a[x][y+1]==2) sum++;
		if(sum>1) return 1;
		else return 0;
	}
	else
	{
		if(x-1>=0)
			if(b[x-1][y]==2) sum++;
		if(x+1<n)
			if(b[x+1][y]==2) sum++;
		if(y-1>=0)
			if(b[x][y-1]==2) sum++;
		if(y+1<m)
			if(b[x][y+1]==2) sum++;
		if(sum>1) return 1;
		else return 0;
	}
}

int check_on_instability(int x, int y) 
{
	if(old_is_a)
	{
		if(x-1>=0)
			if(a[x-1][y]==2 || a[x-1][y]==3) return 1;
		if(x+1<n)
			if(a[x+1][y]==2 || a[x+1][y]==3) return 1;
		if(y-1>=0)
			if(a[x][y-1]==2 || a[x][y-1]==3) return 1;
		if(y+1<m)
			if(a[x][y+1]==2 || a[x][y+1]==3) return 1;
	}
	else
	{
		if(x-1>=0)
			if(b[x-1][y]==2 || b[x-1][y]==3) return 1;
		if(x+1<n)
			if(b[x+1][y]==2 || b[x+1][y]==3) return 1;
		if(y-1>=0)
			if(b[x][y-1]==2 || b[x][y-1]==3) return 1;
		if(y+1<m)
			if(b[x][y+1]==2 || b[x][y+1]==3) return 1;
	}
	return 0;
}


int main()
{
	int k,instable_sum;
	fin>>n>>m>>k;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			fin>>a[i][j];
			c[i][j]=0;
		}
	for(int p=0; p<k; p++)
	{
		instable_sum=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(check_on_stability(i,j)==1)
				{
					if(old_is_a)
						b[i][j]=2;
					else a[i][j]=2;
					
				}
				else
				{
					if(check_on_instability(i,j)==1)
					{
						if(old_is_a)
							b[i][j]=3;
						else a[i][j]=3;
						instable_sum++;	
					}
					else
					{
						if(old_is_a)
							b[i][j]=1;
						else a[i][j]=1;	
					}
				}
				if(a[i][j]!=b[i][j]) c[i][j]++;
			}	
		old_is_a=!old_is_a;
		if(instable_sum==n*m) break;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			fout<<c[i][j]<<" ";
		fout<<endl;
	}
	return 0;
}
