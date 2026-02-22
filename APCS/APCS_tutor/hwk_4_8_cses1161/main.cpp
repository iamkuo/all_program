#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,n;
    ll ans = 0,tmp;
    cin >> x >> n;
    priority_queue<ll,vector<ll>,greater<ll>> sticks;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        sticks.push(tmp);
    }
    for(int i=0;i<n-1;i++)
    {
        tmp = sticks.top();
        sticks.pop();
        tmp += sticks.top();
        sticks.pop();
        sticks.push(tmp);
        ans += tmp;
    }
    cout << ans;
    return 0;
}
