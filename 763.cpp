#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long x,y;
	fin>>x>>y;
	if(x==1 && y==1) fout<<0;
	else if(x==y) fout<<2;
	else fout<<1;
}
