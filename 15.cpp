#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int a,n,s=0;
	fin>>n;
	for(int i=0; i<n*n; i++)
	{
		fin>>a;
		s+=a;
	}
	fout<<(s+1)/2;
	return 0;
}
