#include <fstream> 
#include <vector> 
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");

void swap(int &, int &); 
void Create(vector<int> &, int); 

void Create(vector<int> &V, int N) 
{ 
	if (N==1) 
	{ 
		for(int i=V.size()-1; i>=0; i--) 
			fout<<V[i]; 
		fout<<endl; 
	} 
	else 
	{ 
		for(int i=0; i<N; i++) 
		{ 
			if()swap(V[i], V[N-1]); 
			Create(V, N-1); 
			swap(V[i], V[N-1]); 
		} 
	} 
}
 
void swap(int &a, int &b) 
{ 
	int temp=a; 
	a=b;
	b=temp; 
} 

int main() 
{ 
	vector<int> V; 
	int N; 
	fin >> N; 
	for(int i=0; i<N; i++) 
		V.push_back(i+1); 
	Create(V, V.size()); 
}
