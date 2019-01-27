#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void swap_if_need(int &a,int &b)
{
	if(a<b)
	{
		int c=a;
		a=b;
		b=c;
	}
}

int main()
{
	int n,a[100],sum1=0,sum2=1,min=101,max=-100,max_point,min_point;
	fin>>n;
	for(int i=0; i<n; i++)
	{
		fin>>a[i];
	
		if(a[i]>0) sum1+=a[i];
		if(a[i]>max) 
		{
			max=a[i];
			max_point=i;
		}
		if(a[i]<min) 
		{
			min=a[i];
			min_point=i;
		}
	}
	fout<<sum1<<" ";
	if(n==0) fout<<0;
	else
	{
		swap_if_need(max_point,min_point);
		for(int i=min_point+1; i<max_point; i++)
			sum2*=a[i];
		fout<<sum2;
	}
	return 0;
}
