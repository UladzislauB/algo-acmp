#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	long long temp,n,curent,prev;
	fin>>n>>prev>>curent;
	for(int i=0; i<n-1; i++)
	{
		temp=curent;
		curent=prev;
		prev=temp-curent;	
	}
	fout<<prev<<" "<<curent;
	return 0;
}
