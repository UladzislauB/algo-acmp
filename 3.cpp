#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	unsigned long long n,s=0;
	fin>>n;
	if(n==5) fout<<25;
		else 
		{
			n=n/10;
			fout<<n*(n+1)<<25;
		}
	return 0;
}
