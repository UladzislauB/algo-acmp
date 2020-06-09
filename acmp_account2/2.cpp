#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long res=0;
    for(int i=1; i<=abs(n); i++)
        res += i;
    if(n > 0)
        cout<<res;
    else cout<<1 - res;
    return 0;
}
