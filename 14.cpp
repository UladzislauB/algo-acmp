#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long a,b,i;
	fin>>a>>b;
	if(a<b) swap(a,b);
	for(i=1; i<=b; i++)
		if((a*i)%b==0) 
		{
			fout<<a*i;
			break;
		}
	return 0;
}
