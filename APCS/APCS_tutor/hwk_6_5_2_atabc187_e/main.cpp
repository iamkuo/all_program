#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;

vector<vector<int>> el; // 1-indexed
vector<pii> dfs_order; // 1-indexed
vector<ll> dfs_psum; // 0-indexed
vector<int> parent; // 1-indexed
vector<int> ans; // 0-indexed
int idx=0;

void dfs(int a,int p) // scans the entire tree and complete dfs order
{
    parent[a] = p;
    dfs_order[a].f = idx;
    idx++;
    for(int &i : el[a])
    {
        if(i != p) dfs(i,a);
    }
    dfs_order[a].s = idx;
    idx++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,t,e;
    ll x;
    cin >> n;
    el.resize(n+1);
    ans.resize(n+1);
    dfs_order.resize(n+1);
    parent.resize(n+1);
    dfs_psum.resize(n*2);
    vector<int> a(n),b(n);
    for(int i=0;i<n-1;i++)
    {
        cin >> a[i] >> b[i];
        el[a[i]].push_back(b[i]);
        el[b[i]].push_back(a[i]);
    }
    dfs(1,-1);
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> t >> e >> x;
        int start = (t == 1 ? a[e-1] : b[e-1]);
        int nope = (t == 1 ? b[e-1] : a[e-1]);
        if(parent[nope] == start) // start higher than nope
        {
            dfs_psum[0] += x;
            dfs_psum[dfs_order[nope].f] -= x;
            dfs_psum[dfs_order[nope].s] += x;
        }
        else // nope higher than start
        {
            dfs_psum[dfs_order[start].f] += x;
            dfs_psum[dfs_order[start].s] -= x;
        }
    }
    ll curr = 0;
    for(ll &i : dfs_psum)
    {
        curr += i;
        i = curr;
    }
    for(int i=1;i<=n;i++) cout << dfs_psum[dfs_order[i].f] << "\n";
    return 0;
}
