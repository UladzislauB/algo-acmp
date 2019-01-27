#include <fstream>

using namespace std;

int main()
{
	int n;
	unsigned long long x,y;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n>>x>>y;
	while(x!=y)
	{
		if (x>y) x/=2;
		if (y>x) y/=2;
	}
	fout<<x;
	return 0;
}
