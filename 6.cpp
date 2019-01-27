#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int check1(char* s)
{
	bool flag=true;
	if(strlen(s)!=5) flag=false;
	if(s[0]<'A' || s[0]>'H') flag=false;
	if(s[3]<'A' || s[3]>'H') flag=false;
	if(s[2]!='-') flag=false;
	if(s[1]<'1' || s[1]>'8') flag=false;
	if(s[4]<'1' || s[4]>'8') flag=false;
	if(flag) return 0;
	else
	{
		fout<<"ERROR";
		return 1;
	}
}

void check2(char* s)
{
	bool flag=false;
	if((abs(s[0]-s[3])==1 && abs(s[1]-s[4])==2) ||
	(abs(s[0]-s[3])==2 && abs(s[1]-s[4])==1))
		flag=true;
	if(flag) fout<<"YES";
	else fout<<"NO";
	return;
}


int main()
{
	char s[80];
	fin.getline(s,80);
	if(check1(s)==0)
		check2(s);	
	return 0;
}
