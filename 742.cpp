#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int a[100000],length=1,temp=0;

void mul(int b)
{
	temp=0;
	for(int i=0; i<length; i++)
	{
		a[i]=a[i]*b;
		a[i]+=temp;
		if(a[i]>9)
		{
			temp=a[i]/10;
			a[i]%=10; 
			if(i==length-1) length++;
		}
		else temp=0;
	}	
	
}

unsigned long long fact(int N)
{
    if (N<0)
        return 0;
    else if(N==0)
        return 1;
    else
        return N*fact(N-1);
}
 
unsigned long long combination(int a, int b)
{
    unsigned long long q,p;
    if(b-a<a)
    {
        q=1,p=fact(b-a);
        for(int i=b; i>a; i--)
            q=q*i;  
    }
    else
    {
        q=1,p=fact(a);
        for(unsigned int i=b; i>b-a; i--)
            q=q*i;  
    }
    return q/p; 
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	unsigned long long n,s=1;
	fin>>n;
	n=combination(2,n);
	for(int i=1; i<100000; i++)
		a[i]=0;
	a[0]=1;
	for(int i=0; i<n; i++)
		mul(3);
	for(int i=length-1; i>=0; i--)
		fout<<a[i];
	return 0;
}
