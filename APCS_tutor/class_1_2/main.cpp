#define ll long long
#include <bits/stdc++.h>
using namespace std;
int n,p[20];
ll int l,r,min_diff = 3e10;
vector<bool> c;
void solve(int now, ll int l,ll int r)
{
    if(now == n)
    {
        if(abs(l-r) < min_diff) min_diff = abs(l-r);
        return;
    }
    l += p[now];
    solve(now+1,l,r);
    l -= p[now];
    r += p[now];
    solve(now+1,l,r);
    r -= p[now];
    return;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    solve(0,0,0);
    cout << min_diff;
    return 0;
}
