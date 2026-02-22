#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,t;
vector<int> k;

bool check(ll m)
{
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += m/k[i];
        if(sum >= t) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    k.resize(n);
    for(int i=0;i<n;i++) cin >> k[i];
    ll l=1,r=1e18,m;
    while(l <= r)
    {
        m = (l+r)/2;
        if(check(m))
        {
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    cout << l;
    return 0;
}
