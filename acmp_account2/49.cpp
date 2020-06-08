#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b)
{
    char c;
    c = a;
    a = b;
    b = c;
}

void compare(char &a, char &b){
    if ((a > b && b != '?') || a == '?')
        swap(a, b);
}

int findCommonSetLength(char a, char b) {
    if (a == '?')
        return 10;
    else if (b == '?') {
        if (a >= '0' && a <= '9')
            return 1;
        else return 4;
    }
    else if (a >= '0' && a <= '9') {
        if (b >= '0' && b <= '9') {
            if (a == b)
                return 1;
            else return 0;
        }
        else if (a - (b - 'a' + 48) < 4 &&  a - (b - 'a' + 48) >= 0)
            return 1;
        else return 0;
    }
    else if (b - a < 4)
        return 4 - (b - a);
    else return 0;
}

long long solve(string s1, string s2) {
    long long res = 1;
    for (int i=0; i<s1.length(); i++) {
        compare(s1[i], s2[i]);
        res *= findCommonSetLength(s1[i], s2[i]);
        if (res == 0) break;
    }
    return res;
}


int main() {
    char s1[11], s2[11];
    cin>>s1>>s2;
    cout<<solve(s1, s2);
    return 0;
}
