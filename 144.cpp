#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int a[100000],len=1,temp=0;

void mul(int b)
{
	temp=0;
	for(int i=0; i<len; i++)
	{
		a[i]=a[i]*b;
		a[i]+=temp;
		if(a[i]>9)
		{
			temp=a[i]/10;
			a[i]%=10; 
			if(i==len-1) len++;
		}
		else temp=0;
	}	
	
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	for(int i=1; i<100000; i++)
		a[i]=0;
	char s[103];
	a[0]=1;
	int n;
	fin.getline(s,103);
	fin>>n;
	len=strlen(s);
	for(int i=0; i<len; i++)
		a[i]=s[len-1-i]-'0';
	mul(n);
	if(a[len-1]==0) 
	{
		fout<<0;
	}
	else
	for(int i=len-1; i>=0; i--)
		fout<<a[i];
	return 0;
}
