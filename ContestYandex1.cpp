#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int check(long long s,long long l1,long long r1,long long l2,long long r2)
{
	if(s>=l1+l2 && s<=r1+r2) return 1;
	else return 0;
}

int main()
{
	long long s,l1,r1,l2,r2,i;
	fin>>s>>l1>>r1>>l2>>r2;
	if(check(s,l1,r1,l2,r2)==1)
	{
		fout<<s-min(s-l1,r2)<<" "<<min(s-l1,r2);
	}
	else fout<<-1;
	return 0;
}
