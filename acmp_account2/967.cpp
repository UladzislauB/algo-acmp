#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int countDigitSum(long long a, int k)
{
    int res = 0;
    while (a >= k){
        res += a % k;
        a = a/k;
    }
    return res + a;
}

int main()
{
    int n, k1, k2;
    cin>>n>>k1>>k2;
    vector<long> b;
    for(int i=0; i<n; i++)
    {
        long a;
        cin>>a;
        b.push_back(countDigitSum(a, k1)*countDigitSum(a, k2));
    }
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++)
        cout<<b[i]<<' ';
    return 0;
}
