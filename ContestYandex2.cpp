#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int min1,min2,min3,min4,min5;

void new_elem(int elem)
{
	int temp;
	if(elem<min1) 
	{
		temp=min1;
		min1=elem;
		new_elem(temp);
	}
	else if(elem<min2) 
	{
		temp=min2;
		min2=elem;
		new_elem(temp);
	}
	else if(elem<min3)
	{
		temp=min3;
		min3=elem;
		new_elem(temp);
	}
	else if(elem<min4) 
	{
		temp=min4;
		min4=elem;
		new_elem(temp);
	}
	else if(elem<min5)
	{
		temp=min5;
		min5=elem;
		new_elem(temp);
	}
}

void print()
{
	if(min5<2000000) fout<<min5<<" ";
	if(min4<2000000) fout<<min4<<" ";
	if(min3<2000000) fout<<min3<<" ";
	if(min2<2000000) fout<<min2<<" ";
	if(min1<2000000) fout<<min1<<" ";
	fout<<endl;
}

int main()
{
	min1=2000000;
	min2=2000000;
	min3=2000000;
	min4=2000000;
	min5=2000000;
	int n,elem;
	fin>>n;
	for(int i=0; i<n; i++)
	{
		fin>>elem;
		new_elem(elem);
		print();
	}
	return 0;
}
