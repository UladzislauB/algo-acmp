#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long a,b,c,d,i;
	fin>>a>>b>>c>>d;
	for(i=-100; i<101; i++)
		if(a*i*i*i+b*i*i+c*i+d==0) fout<<i<<" ";
	return 0;
}
