#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int>> el;
vector<int> a;
vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    el.resize(n+1);
    a.resize(n+1);
    dp.resize(n+1,2e9); // A of lowest price node that can reach i
    for(int i=1;i<=n;i++) cin >> a[i];
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        el[y].pb(x); // build a reverse graph
    }
    int ans = -2e9;
    for(int i=2;i<=n;i++)
    {
        for(int start : el[i]) // start < i guaranteed by question
        {
            //cout << start << " can go to " << i << "\n";
            if(min(dp[start],a[start]) < dp[i]) dp[i] = min(dp[start],a[start]);
        }
        if(a[i] - dp[i] > ans) ans = a[i]-dp[i];
        //for(int i : dp) cout << i << " ";
        //cout << "\n";
    }
    cout << ans;
    return 0;
}
