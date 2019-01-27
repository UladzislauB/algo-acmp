#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=0;
	fin>>n;
	if(n<1)
		for(int i=n; i<=1; i++)
			s+=i;
	else
		for(int i=1; i<=n; i++)
			s+=i;
	fout<<s;
	return 0;
}
