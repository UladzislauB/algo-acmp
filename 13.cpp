#include <fstream>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int a[10],b[10],sum1=0,sum2=0;
	for(int i=0; i<10; i++)
	{
		a[i]=0;
		b[i]=0;
	}
	char s1[5],s2[5];
	fin>>s1>>s2;
	for(int i=0; i<4; i++)
		if(s1[i]==s2[i]) sum1++;
			else {
				a[s1[i]-'0']++;
				b[s2[i]-'0']++;
			}
	for(int i=0; i<10; i++)
		sum2+=min(a[i],b[i]);
	fout<<sum1<<" "<<sum2;
	return 0;
}
