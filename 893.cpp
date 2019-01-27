#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n,s=1;
	fin>>n;
	if(n<3) fout<<n;
		else
		{
			for(long long i=n;i>n-3; i--)
				s=s*i;
			fout<<s;
		}
		
	return 0;
}
