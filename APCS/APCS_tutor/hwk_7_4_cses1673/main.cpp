#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
using namespace std;

vector<bool> vis;

void dfs(int x,vector<vector<int>> &el, vector<bool> &res)
{
    vis[x] = true;
    res[x] = true;
    for(auto &dest : el[x])
    {
        if(!vis[dest]) dfs(dest,el,res);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> el(n+1); // (dest,x)
    vector<vector<int>> rev_el(n+1);
    vector<vector<int>> simp_el(n+1);
    vector<bool> from_1(n+1,false);
    vector<bool> to_n(n+1,false);
    int a,b,x;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> x;
        el[a].pb({b,x});
        simp_el[a].pb(b);
        rev_el[b].pb(a);
    }
    vis.resize(n+1,false);
    dfs(1,simp_el,from_1);
    vis.assign(n+1,false);
    dfs(n,rev_el,to_n);
    vector<ll> dist(n+1,-1e16);
    vector<int> u_c(n+1,0);
    vector<bool> in_bfs(n+1,false);
    queue<int> bfs;
    dist[1] = 0;
    bfs.push(1);
    in_bfs[1] = true;
    u_c[1] = 1;
    int c;
    while(!bfs.empty())
    {
        c = bfs.front();
        bfs.pop();
        in_bfs[c] = false;
        for(pii &i : el[c])
        {
            int &dest = i.f;
            int &x = i.s;
            if(from_1[dest] && to_n[dest])
            {
                if(dist[dest] < dist[c]+(ll)x)
                {
                    dist[dest] = dist[c]+x;
                    if(!in_bfs[dest])
                    {
                        u_c[dest]++;
                        if(u_c[dest] >= n)
                        {
                            cout << -1;
                            return 0;
                        }
                        bfs.push(dest);
                        in_bfs[dest] = true;
                    }
                }
            }
        }
    }
    cout << dist[n];
    return 0;
}
