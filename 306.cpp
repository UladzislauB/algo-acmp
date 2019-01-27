#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int count=0;
char a[1003];

void shift_two()
{
	for(int i=count-1; i>=0; i--)
		a[i+2]=a[i];
}

int main()
{
	int n;
	fin>>n;
	if(n==1)
		fout<<"B";
	else
	{
		bool B;
		if(n%2==0) B=false;
			else B=true;
		for(int j=0; j<n; j++)
		{
			shift_two();
			a[1]=a[count+1];
			if(B) a[0]='B';
				else a[0]='R';
			count++;
			B=!B;
		}	
		for(int i=0; i<n; i++)
			fout<<a[i];
	}	
	return 0;
}
