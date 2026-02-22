#include <bits/stdc++.h>
#define pb push_back
#define pq priority_queue
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> el(n+1);
    vector<int> in_deg(n+1,0);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        el[a].pb(b);
        in_deg[b]++;
    }
    /*debug
    for(int i : in_deg) cout << i << " ";
    cout << "\n";
    //*/
    int curr,confirmed=0;
    pq<int,vector<int>,greater<int>> bfs;
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i] == 0) bfs.push(i);
    }
    vector<int> ans(n);
    while(!bfs.empty())
    {
        curr = bfs.top();
        bfs.pop();
        ans[confirmed] = curr;
        confirmed++;
        for(int i : el[curr])
        {
            in_deg[i]--;
            if(in_deg[i] == 0) bfs.push(i);
        }
    }
    if(confirmed != n)
    {
        cout << -1;
        return 0;
    }
    for(int i : ans) cout << i << " ";
    return 0;
}
