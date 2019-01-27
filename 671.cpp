#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

unsigned long long fact(unsigned long long N)
{
	if(N<0)
		return 0;
	else if(N==0)
		return 1;
	else return N*fact(N-1);
}

unsigned long long combination(unsigned long long m, unsigned long long n)
{
	unsigned long long c=1;
	if(n-m>m)
	{
		for(int i=n-m+1; i<=n; i++)
			c*=i;
		c/=fact(m);
	}
	else
	{
		for(int i=m+1; i<=n; i++)
			c*=i;
		c/=fact(n-m);
	}
	return c;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char s[35];
	fin.getline(s,35);
	unsigned long long sum=0,len=strlen(s);
	for(int i=1; i<len; i++)
		sum+=pow(2,i);
	if(s[0]-'0'<4 && len==1)
		sum=0;
	else
	if(s[0]-'0'>7)
		sum+=pow(2,len);
	else if(s[0]-'0'==7)
	{
		int temp=pow(2,len);
		for(int i=0; i<len; i++)
		{
			if(s[i]-'0'>8) break;
				else
			if(s[i]-'0'<7 && s[i]-'0'>4)
			{
				temp-=pow(2,len-i-1);
				break;
			}
			else 
			if(s[i]-'0'<4)
			{
				temp-=pow(2,len-i);
				break;
			}
			else
			if(s[i]-'0'==4)
				temp-=pow(2,len-i-1);
		}
		
		sum+=temp;
	}	
	else if(s[0]-'0'==4)
	{
		int temp=pow(2,len-1);
		for(int i=1; i<len; i++)
		{
			if(s[i]-'0'>8) break;
				else
			if(s[i]-'0'<7 && s[i]-'0'>4)
			{
				temp-=pow(2,len-i-1);
				break;
			}
			else 
			if(s[i]-'0'<4)
			{
				temp-=pow(2,len-i);
				break;
			}
			if(s[i]-'0'==4)
				temp-=pow(2,len-i-1);
		}
		sum+=temp;
	}
	else if(s[0]-'0'>4)	
		sum+=pow(2,len-1);
	fout<<sum;
	return 0;
}
