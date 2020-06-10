#include <iostream>

using namespace std;

void rotateLeft(int &dir1, int &dir2) {
    if (dir2 == 0){
        dir2 = -dir1;
        dir1 = 0;
    } else {
        dir1 = dir2;
        dir2 = 0;
    }
}


int getSolution(string s)
{
    int a[110][110] = {};
    int currX = 55, currY = 55;
    a[55][55] = 1;
    int dirX = 1, dirY = 0;
    int res = 0;

    for(int i = 0; i < s.length(); i++)
        switch(s[i]){
        case 'S':
            currX += dirX;
            currY += dirY;
            res ++;
            if (a[currX][currY] == 1)
                return res;
            a[currX][currY] = 1;
            break;
        case 'L':
            rotateLeft(dirX, dirY);
            break;
        case 'R':
            rotateLeft(dirY, dirX);
            break;
        }

    return -1;
}

int main()
{
    string s;
    cin>>s;
    cout<<getSolution(s);
    return 0;
}
