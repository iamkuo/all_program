#include<bits/stdc++.h>
using namespace std;

int f(int x) {return x*2 - 3;}

int g(int x, int y) {return x*2 + y - 7;}

int h(int x, int y, int z) {return x*3 - y*2 + z;}

int read()
{
    char dat[11];
    int x,y,z;
    cin >> dat;
    if(dat[0] == 'f') return f(read());

    if(dat[0] == 'g')
    {
        int x = read();
        int y = read();
        return g(x, y);
    }

    if(dat[0] == 'h')
    {
        int x = read();
        int y = read();
        int z = read();
        return h(x,y,z);
    }
    return atoi(dat);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << read() << endl;
}
