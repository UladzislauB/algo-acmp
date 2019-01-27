#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long x1,y1,x2,y2,xa,ya,xb,yb;
	fin>>x1>>y1>>x2>>y2>>xa>>ya;
	if(x1==x2)
	{
		xb=2*x1-xa;
		yb=ya;
	}
	else
	{
		yb=y1*2-ya;
		xb=xa;
	}
	fout<<xb<<" "<<yb;
	return 0;
}
