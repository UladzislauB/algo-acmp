#include <fstream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> combination;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n,mn=3001,arr[100][100];

void next_combination(int offset, int k) {
  if (k == 0) {
  	int temp=arr[combination[0]-1][combination[1]-1]+
  		arr[combination[1]-1][combination[2]-1]+
  		arr[combination[2]-1][combination[0]-1];
    if(temp<mn) mn=temp;
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    next_combination(i+1, k-1);
    combination.pop_back();
  }
}

int main() 
{
	int k = 3;
	
	fin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin>>arr[i][j];
	
	for (int i = 0; i < n; ++i) 
		people.push_back(i+1);
	next_combination(0, k);
	
	fout<<mn;	
	return 0;
}
