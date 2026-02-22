#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
using namespace std;

vector<vector<int>> el;
vector<int> dsu;
//which group does every node belongs to, start at id 0
vector<int8_t> color;

int idx=0;
//current group

void dfs_group(int x)
{
    dsu[x] = idx;
    for(int i : el[x])
    {
        if(dsu[i] == -1) dfs_group(i);
    }
}

void dfs_color(int x,int prev)
{
    color[x] = 1-prev;
    for(int i : el[x])
    {
        if(color[i] == -1) dfs_color(i,1-prev);
    }
}

bool dfs_partial(int x, int c, vector<vector<pii>>& tmp, vector<int8_t>& tmp_color)
{
    tmp_color[x] = c;
    for(auto &[dest,rel] : tmp[x])
    {
        if(tmp_color[dest] == -1)
        {
            if(!dfs_partial(dest,c^(!rel),tmp,tmp_color)) return false;
        }
        else if(tmp_color[dest] != c^!(rel)) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    dsu.resize(n,-1);
    color.resize(n,-1);
    el.resize(n);
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        el[a].pb(b);
        el[b].pb(a);
    }
    for(int i=0;i<n;i++)
    {
        if(dsu[i] == -1)
        {
            dfs_group(i);
            idx++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(color[i] == -1) dfs_color(i,1);
    }
    int p,k;
    cin >> p >> k;
    bool ok;
    for(int i=0;i<p;i++)
    {
        vector<vector<pii>> tmp(idx);
        vector<int8_t> tmp_color(idx,-1);
        ok = true;
        for(int j=0;j<k;j++)
        {
            cin >> a >> b;
            if(!ok) continue;
            if(dsu[a] == dsu[b] && color[a] == color[b])
            {
                ok = false;
                continue;
            }
            int w = color[a]^color[b];
            tmp[dsu[a]].pb({dsu[b],w});
            tmp[dsu[b]].pb({dsu[a],w});
        }
        if(!ok)
        {
            cout << i+1 << "\n";
            continue;
        }
        //dfs scan compressed graph
        int tmp_idx=0;
        for(int j=0;j<idx;j++)
        {
            if(tmp_color[j] == -1)
            {
                if(!dfs_partial(j,tmp_idx,tmp,tmp_color))
                {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) cout << i+1 << "\n";
    }
    return 0;
}
