#include <fstream>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;


int compatibility(char a, char b)
{
	int temp=4-abs(a-b);
	if (temp>=0) return temp;
		else return 0;
}

int check(char c1,char c2)
{
	if(c1=='?' || c2=='?')
	{
		if(c1==c2) 
			return 10;
		else if((c1>='0' && c1<='9') || (c2>='0' && c2<='9'))	
			return 1;
		else if((c1>='a' && c1<='g') || (c2>='a' && c2<='g'))
			return 4;
	}
	else if((c1>='0' && c1<='9') || (c2>='0' && c2<='9'))
	{
		if(c1==c2)
			return 1;
		else if(c1>='0' && c1<='9')
		{
			int temp=(c1-'0')-(c2-'a');
			if(temp>=0 && temp<=3)	return 1;
				else return 0;
		}
		else if(c2>='0' && c2<='9')
		{
			int temp=(c2-'0')-(c1-'a');
			if(temp>=0 && temp<=3)	return 1;
				else return 0;
		}
	}
	else return compatibility(c1,c2);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char a[10],b[10];
	fin.getline(a,10);
	fin.getline(b,10);
	unsigned long long s=1;
	int len=strlen(a),counter=0;
	for(int i=0; i<len; i++)
		s*=check(a[i],b[i]);
	fout<<s;
	return 0;
}
