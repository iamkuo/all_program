#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> el(n+1);
    vector<int> dis(n+1,-1);
    vector<int> prev(n+1,-1);
    dis[1] = 1;
    int a,b;
    bool found = false;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        el[a].push_back(b);
        el[b].push_back(a);
    }
    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty())
    {
        vector<int> &dest = el[bfs.front()];
        for(int i=0;i<dest.size();i++)
        {
            if(dis[dest[i]] != -1) continue;
            dis[dest[i]] = dis[bfs.front()]+1;
            prev[dest[i]] = bfs.front();
            //cout << "distance to " << dest[i] << " is " << dis[dest[i]] << "\n";
            if(dest[i] == n)
            {
                found = true;
                break;
            }
            bfs.push(dest[i]);
        }
        if(found) break;
        bfs.pop();
    }
    if(dis[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    for (int v=n;v!=-1;v=prev[v]) ans.push_back(v);
    cout << dis[n] << "\n";
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
    return 0;
}
