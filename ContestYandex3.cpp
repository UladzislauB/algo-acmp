#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int main()
{
	double n,a[100000],min=1000000;
	fin>>n;
	bool flag=false;
	for(int i=0; i<n; i++)
	{
		fin>>a[i];	
		if(a[i]<min && a[i]!=0) min=a[i];
		if(a[i]!=0) flag=true;
	}
	if(flag)
		fout<<fixed<<setprecision(9)<<min;
	else
		fout<<fixed<<setprecision(9)<<0;
	return 0;
}
