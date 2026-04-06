#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int>> el;
vector<int> dp;
vector<int> start;

void dfs(int x)
{
    for(int i : el[x])
    {
        if(dp[i] == -1) dfs(i);
        if(dp[i]+1 > dp[x]) dp[x] = dp[i]+1;
    }
    if(dp[x] == -1) dp[x] = 0; //x is leaf
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    el.resize(n+1);
    vector<bool> if_in(n+1,false);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        el[x].pb(y);
        if_in[y] = true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!if_in[i]) start.pb(i);
    }
    int ans = 0;
    dp.resize(n+1,-1);
    //the max distance reachable when start at i
    for(int i : start)
    {
        //cout << "searching " << i << "\n";
        dfs(i);
        if(dp[i] > ans) ans = dp[i];
    }
    cout << ans;
    return 0;
}
