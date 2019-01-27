#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int next(int curent)
{
	if(curent==1)
	return 2;
	else if(curent==2)
	return 3;
	else return 1;
}

int prostoe_li(int n)
{
	for (int i = 2; i<sqrt(n); i++) {
    if (n % i == 0) {
        return 0;
    }
    return 1;
}
}

int main()
{
	int prost[100],counter=0;
	for(int i=2; i<100; i++)
		if(i<14)
		{
			if(prostoe_li(i)==1)
			{
				prost[counter]=i;	
				counter++;
			}	
		}
		else if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i%11!=0 && i%13!=0)
			if(prostoe_li(i)==1)
			{
				prost[counter]=i;	
				counter++;
			}	

	long long n,div=2;
	fin>>n;
	bool flag=false;
	int curent=1;
	for(int p=0; p<100; p++)
	{
		bool pometka=false;
		long long first,sec;
		for(int div=2; div<sqrt(n); div++)
		if(n%div==0)
		{
	    		if(!pometka )
	    		{
	    			first=div;
	    			sec=n/div;
	    			pometka=true;
	    		}
	    		//proverka na prostotu
	    		bool io=false;
	    		for(int u=0; u<counter; u++)
	    		{
	    			if(prost[u]==div+n/div)
	    			{
	    				io=true;
	    				break;
	    			}
	    			if(prost[u]<div+n/div)
	    				break;
	    		}
	    			
	    		if(io)
	    		{
	    			flag==true;
	    			break;
	    		}
	    	}	
		for(int u=0; u<counter; u++)
	    		if(prost[u]==n)
	    		{
	    			flag=true;
	    			break;
	    		}		
		if(flag) break;
		else
		{
			n=first+sec;
			curent=next(curent);
		}
		
	}
	if(flag) fout<<curent;
	else fout<<0;

}
