#include <iostream>
#include <string>

using namespace std;

long long fact(int n)
{
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    else return n * fact(n - 1);
}

long long solve(string s) {
    int a[26] = {};
    for (int i=0; i<s.length(); i++)
        a[s[i] - 'a']++;
    long long res = fact(s.length());
    for (int i=0; i<26; i++)
        res /= fact(a[i]);
    cout<<res;
}

int main()
{
    string s;
    cin>>s;
    solve(s);
    return 0;
}
