#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int elem,n,even[100],odd[100],e=0,o=0;
	fin>>n;
	for(int i=0; i<n; i++)
	{
		fin>>elem;
		if(elem%2==1)
		{
			odd[o]=elem;	
			o++;
		}
		else
		{
			even[e]=elem;
			e++;
		}
	}
		for(int i=0; i<o; i++)
			fout<<odd[i]<<" ";
		fout<<endl;
		for(int i=0; i<e; i++)
			fout<<even[i]<<" ";
		fout<<endl;
	if(e>=o) fout<<"YES";
	else fout<<"NO";
	return 0;	
}
