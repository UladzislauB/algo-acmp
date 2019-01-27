#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

unsigned long long fact(unsigned long long N)
{
	if(N<0)
		return 0;
	else if(N==0)
		return 1;
	else return N*fact(N-1);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char s[16];
	fin.getline(s,16);
	unsigned long long len=strlen(s),repeat[26],sum;
	for(int i=0; i<26; i++)
		repeat[i]=0;
	for(int i=0; i<len; i++)
		repeat[s[i]-'a']++;
	sum=fact(len);
	for(int i=0; i<26; i++)
		sum/=fact(repeat[i]);
	fout<<sum;
	return 0;
}
