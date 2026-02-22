#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,slowest=-1;
    cin >> n;
    long long total=0;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        total += t;
        if(t > slowest) slowest = t;
    }
    if(slowest*2 > total) cout << slowest*2;
    else cout << total;
    return 0;
}
