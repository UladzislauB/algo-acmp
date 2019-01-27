#include <fstream>
#include <cstdlib>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int compare(const void * x1, const void * x2)   
{
  return ( *(int*)x1 - *(int*)x2 );             
}

int main()
{
	long v[100000];
	unsigned long long n,m,f,p;
	fin>>n>>m>>f>>p;
	if(p==0)
	{
		unsigned long long door=0,floor=0;
		door=(f-1)/(4*m)+1;
		floor=((f-1)%(4*m))/4+1;
		fout<<door<<" "<<floor;
	}
	else
	{
		for(int i=0; i<p; i++)
			fin>>v[i];
		qsort(v, p, sizeof(int), compare);
		
		unsigned long long door=1,floor=1;
		while(f>(m-1)*4+3)
		{
			bool flag=false;
			for(int i=0; i<p; i++)
			{
				if(v[i]==door)
				{
					flag=true; 
					break;
				}
				if(v[i]>door)
					break;
			}
			if(flag) f-=((m-1)*4+3);
			else f-=(m*4);
			door++;
		}
		bool flag=false;
		for(int i=0; i<p; i++)
		{
			if(v[i]==door)
			{
				flag=true; 
				break;
			}
			if(v[i]>door)
				break;
		}
		if(f==0)
		{
			door--;
			floor=m;
		}
		else if(flag)
		{
			if(f<4) floor=1;
			else
			{
				f-=3;
				floor=2+(f-1)/4;
			}
		}
		else floor=(f-1)/4+1;
		fout<<door<<" "<<floor;	
	}
	return 0;
}
