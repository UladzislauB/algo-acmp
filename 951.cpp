#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int k,x[10],y[10],i,j,n,m,max_path=0;
	fin>>n>>m>>k;
	for(int p=0; p<k; p++)
		fin>>x[p]>>y[p];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			int temp=10000;
			for(int p=0; p<k; p++)
				if(temp>abs(i-x[p]+1)+abs(j-y[p]+1))
					temp=abs(i-x[p]+1)+abs(j-y[p]+1);
			if(max_path<temp) max_path=temp;
		}
	fout<<max_path;
	return 0;
}
