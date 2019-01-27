#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long a,b;
	fin>>a>>b;
	if(a<b) fout<<"<";
	else if(a>b) fout<<">";
	else fout<<"=";
	return 0;
}
