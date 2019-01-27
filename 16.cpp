#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n,a[100];
	fin>>n;
	for(int i=1; i<n; i++)
		a[i]=0;
	a[0]=1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=(i+1)/2-1; j++)
			a[i]+=a[j];
		if((i+1)%2==1) a[i]++;
	}
	fout<<a[n-1];
	return 0;
}
