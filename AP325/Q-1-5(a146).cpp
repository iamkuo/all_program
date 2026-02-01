#include<bits/stdc++.h>
using namespace std;

string s;
int k = 0;

int scan(int n)
{
    switch(s[k++])
    {
        case '0':
            return 0;
        case '1':
            return n*n;
        case '2':
            return scan(n/2)+scan(n/2)+scan(n/2)+scan(n/2);;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> s >> n;
    cout << scan(n);
    return 0;
}
