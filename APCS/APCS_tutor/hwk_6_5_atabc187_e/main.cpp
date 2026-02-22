#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> el;
vector<long long> c;
vector<int> parent;
long long x;

void dfs_parent(int curr, int nope)
{
    parent[curr] = nope;
    for(int i : el[curr])
    {
        if(i == nope) continue;
        dfs_parent(i,curr);
    }
}

void dfs_p_sum(int curr, int nope)
{
    for (int i : el[curr])
    {
        if (i == nope) continue;
        c[i] += c[curr];
        dfs_p_sum(i, curr);
    }
}

int main()
{
    int n,q,t,e;
    cin >> n;
    el.resize(n+1);
    c.resize(n+1,0);
    parent.resize(n+1,-1);
    vector<int> a(n),b(n);
    for(int i=0;i<n-1;i++)
    {
        cin >> a[i] >> b[i];
        el[a[i]].push_back(b[i]);
        el[b[i]].push_back(a[i]);
    }
    dfs_parent(1,-1);
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> t >> e >> x;
        int u = a[e - 1];
        int v = b[e - 1];
        int start = (t == 1 ? u : v);
        int block = (t == 1 ? v : u);
        if(parent[block] == start)
        {
            c[1] += x;
            c[block] -= x;
        }
        else c[start] += x;
    }
    dfs_p_sum(1,-1);
    for(int i=1;i<=n;i++) cout << c[i] << "\n";
    return 0;
}
