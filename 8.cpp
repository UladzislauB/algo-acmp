#include <fstream> 

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int a,b,c;
	fin>>a>>b>>c;
	if(a*b==c) fout<<"YES";
	else fout<<"NO";
	return 0;
}
