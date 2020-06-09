#include <iostream>

using namespace std;

long long countVariation(int n, int k){
    long long res = 1;
    for (int i=0; i < k; i++)
    {
        res *= n;
        n--;
    }
    return res;
}

long long countCombination(int m, int n) {
    if (n-m > m)
        return countVariation(n, m) / countVariation(m, m);
    else return countVariation(n, n - m) / countVariation(n - m, n - m);
}


long long solve(int n, int m) {
    return countVariation(n, m) * countCombination(m, n);
}

int main()
{
    int n, m;
    cin>>n>>m;
    cout<<solve(n,m);

    return 0;
}
