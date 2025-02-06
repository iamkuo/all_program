#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long int ans = 0;
bool first = true;

void go(int last)
{
    int now;
    cin >> now;
    if(first)
    {
        //last = 0,abs(now-last) = now
        first = false;
        ans -= now;
    }
    ans += abs(last-now);
    if(now == 0)
    {
        ans -= abs(last-now);
        return;
    }
    if(now%2 == 0)
    {
        go(now);
        go(now);
        return;
    }
    if(now%2 == 1)
    {
        go(now);
        go(now);
        go(now);
        return;
    }
}

int main()
{
    go(0);
    cout << ans;
    return 0;
}
