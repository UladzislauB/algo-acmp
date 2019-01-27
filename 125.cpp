#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n,arr[100][100],indicators[100],s=0;
	fin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin>>arr[i][j];
	for(int i=0; i<n; i++)
		fin>>indicators[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(arr[i][j]==1)
			{
				if(indicators[i]!=indicators[j])
					s++;
				arr[i][j]=0;
				arr[j][i]=0;
			}
	fout<<s;
	return 0;
}
