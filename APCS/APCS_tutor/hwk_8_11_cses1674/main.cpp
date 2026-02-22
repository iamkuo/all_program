#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> out_deg;
vector<vector<int>> el;

void dfs(int x)
{
    if(el[x].size() == 0) return;
    for(int i : el[x])
    {
        dfs(i);
        out_deg[x] += out_deg[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    el.resize(n+1);
    out_deg.resize(n+1,0);
    int tmp;
    for(int i=2;i<=n;i++)
    {
        cin >> tmp;
        el[tmp].pb(i);
        out_deg[tmp]++;
    }
    /*debug
    for(int i : out_deg) cout << i << " ";
    cout << "\n";
    //*/
    dfs(1);
    for(int i=1;i<=n;i++) cout << out_deg[i] << " ";
    return 0;
}
