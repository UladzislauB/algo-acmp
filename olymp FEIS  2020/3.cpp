#include <iostream>
#include <string>
#include <map>

using namespace std;

int translateToArab(string s) {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int temp = 0;
    int res = 0;
    for (char c: s) {
        int number = m[c];
        if (number < temp) {
            res += temp;
            temp = number;
        }
        else if (number > temp)
        {
            if (temp == 0) {
                temp = number;
            }
            else
            {
                res += number - temp;
                temp = 0;
            }
        }
        else if (number == temp) {
            res += temp + number;
            temp = 0;
        }
    }
    return res + temp;
}

string translateToRoman(int n) {
    const int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	const char *symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int counter = 12;
    string result;
    while(counter >= 0) {
		while(n >= values[counter]) {
			n -= values[counter];
			result += symbols[counter];
		}
		counter--;
	}
    return result;
}


string calculate(string s) {
    string str1 = "+";
    string str2 = "-";
    size_t found1 = s.find(str1); 
    size_t found2 = s.find(str2);
    size_t found = 0;
    if (found1 != string::npos)
        found = found1;
    else if (found2 != string::npos)
        found = found2;
    int result;
    if (s[found] == '+')
        result = translateToArab(s.substr(0, found)) + translateToArab(s.substr(found + 1, s.length()));
    else 
        result = translateToArab(s.substr(0, found)) - translateToArab(s.substr(found + 1, s.length()));
    return translateToRoman(result);
}

int main(){
    string s;
    cin >> s;
    cout << calculate(s);
    return 0;
}