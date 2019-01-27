#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=1;
	fin>>n;
	for(int i=0; i<n; i++)
		s=s*2;
	fout<<s-n-1;
	return 0;
}
