#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	short int n;
	fin>>n;
	fout<<n<<9<<9-n;
	return 0;
}
