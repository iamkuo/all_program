#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int>> el;
vector<int> h;

void dfs(int x)
{
    for(int i : el[x])
    {
        if(h[i] == -1) dfs(i);
        h[x] = max(h[i]+1,h[x]);
    }
    if(h[x] == -1) h[x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,tmp;
    cin >> n;
    el.resize(n+1);
    h.resize(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin >> k;
        for(int j=0;j<k;j++)
        {
            cin >> tmp;
            el[i].pb(tmp);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(h[i] != -1) continue;
        dfs(i);
    }
    int root,root_h=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i] > root_h)
        {
            root = i;
            root_h = h[i];
        }
        ans += h[i];
    }
    cout << root << "\n" << ans;
    return 0;
}
