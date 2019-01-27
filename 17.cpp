#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int index,n,a[32100],minC=1110010;
	for(int i=0; i<32100; i++)
		a[i]=0;
	fin>>n;
	for(int i=0; i<n; i++)
	{
		fin>>index;
		a[index-1]++;
	}
	for(int i=0; i<32100; i++)
		if(a[i]!=0) minC=min(minC,a[i]);
	fout<<(n-1)/minC;
	return 0;
}
