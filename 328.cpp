#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=0;
	fin>>n;
	for(int i=1; i<=n; i++)
		s=s+i*(n+2);
	fout<<s;
	return 0;
}
