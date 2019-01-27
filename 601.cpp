#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Pair
{
	public:
		int input,output;
		
};

int main()
{
	Pair** colors=new Pair* [100];
	for(int i=0; i<100; i++)
		colors[i]=new Pair[1000];
	int n,m,color,curent=1,a,b,counters[100],k;
	for(int i=0; i<100; i++)
		counters[i]=0;
	fin>>n>>m;
	for(int i=0; i<m; i++)
	{
		fin>>a>>b>>color;
		colors[color-1][counters[color-1]].input=a;
		colors[color-1][counters[color-1]].output=b;
		counters[color-1]++;
	}
	fin>>k;
	bool flag=true;
	for(int i=0; i<k; i++)
	{
		flag=true;
		fin>>color;
		color--;
		for(int j=0; j<counters[color]; j++)
			if(colors[color][j].input==curent)
			{
				flag=false;
				curent=colors[color][j].output;
				break;
			}
			else if(colors[color][j].output==curent)
			{
				flag=false;
				curent=colors[color][j].input;
				break;
			}
		if(flag) break;
	}
	if(flag) fout<<"INCORRECT";
	else fout<<curent;
	return 0;
}
