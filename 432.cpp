#include <fstream>
#include <stdio.h>
using namespace std;

FILE *f = fopen("input.txt", "r"); 
FILE *f2 = fopen("output.txt", "w"); 
ofstream fout("output.txt");

int a[202][202],n,m,counter=0,sum=0;

void search(int x,int y)
{
	if(a[x][y]==1) sum--;
	a[x][y]=0;
	if(a[x+1][y]==1)
		search(x+1,y);
	if(a[x-1][y]==1)
		search(x-1,y);
	if(a[x][y+1]==1)
		search(x,y+1);	
	if(a[x][y-1]==1)
		search(x,y-1);
}

int main()
{
	char s[201];
	fscanf(f,"%d%d",&n,&m);
	for(int i=0; i<n+2; i++)
	{
		if(i>0 &&i <n+1)
			fscanf(f,"%s",s);
		for(int j=0; j<m+2; j++)
			if(i==0 || j==0 || i==n+1 || j==m+1)
				a[i][j]=0;
			else
			{	
				if(s[j-1]=='#') 
				{
					a[i][j]=1;
					sum++;
				}
				else a[i][j]=0;	
			}
	}		
	for(int i=0; i<n+2; i++)
		for(int j=0; j<m+2; j++)
		{
			if(a[i][j]==1) 
			{
				search(i,j);
				counter++;
			}
			if(sum==0) break;
		}	
	fprintf(f2,"%d",counter);
	fclose(f);
	fclose(f2);
	return 0;
}
