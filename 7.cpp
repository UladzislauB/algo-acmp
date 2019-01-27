#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int check_length(int a,int b,int c)
{
	if(a>b && a>c) return 1;
	else if (b>a && b>c) return 2;
	else if (c>a && c>b) return 3;
	else return 0;
}

void print(int* a, int len)
{
	for(int i=0; i<len; i++)
		fout<<a[i];
}

int compare(int* a,int* b,int len)
{
	int flag=1;
	for(int i=0; i<len; i++)
	if(a[i]>b[i]) break;
		else if(a[i]<b[i])
		{
			flag=0; 
			break;
		}
	return flag;
}


int main()
{
	char s[500];
	fin.getline(s,500);
	int a[110],b[110],c[110],count=0,curent=0,len1=0,len2=0,len3=0;
	for(int i=0; i<strlen(s); i++)
	{
		if(s[i]==' ') 
		{
			count++;
			curent=0;
		}
		else
		{
			if(count==0)
			{
				a[curent]=s[i]-'0';
				curent++;
				len1++;
			}	
			if(count==1)
			{
				b[curent]=s[i]-'0';
				curent++;
				len2++;
			}	
			if(count==2)
			{
				c[curent]=s[i]-'0';
				curent++;
				len3++;
			}		
		}
	}
	int res=check_length(len1,len2,len3);
	if(res!=0)
	{
		if(res==1)
			print(a,len1);
		else if(res==2)
			print(b,len2);
		else if(res==3)
			print(c,len3);
	}
	else
	{
		if(len1==len2 && len2==len3)
		{
			if(compare(a,b,len1)==1 && compare(a,c,len1)==1)
				print(a,len1);
			else if(compare(b,a,len1)==1 && compare(b,c,len1)==1)
				print(b,len1);
			else if(compare(c,b,len1)==1 && compare(c,a,len1)==1)
				print(c,len1);
		}
		else if(len1==len2)
		{
			if (compare(a,b,len1)==1) 
				print(a,len1);
			else print(b,len2);
		}
		else if(len1==len3)
		{
			if (compare(a,c,len1)==1) 
				print(a,len1);
			else print(c,len3);
		}
		else if(len2==len3)
		{
			if (compare(b,c,len2)==1) 
				print(b,len2);
			else print(c,len3);
		}
	}
	
	
	return 0;
}
