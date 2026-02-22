#include <bits/stdc++.h>
#define pb push_back
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
    queue<int> bfs;
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i] == 0) bfs.push(i);
    }
    int c;
    vector<int> ans;
    vector<bool> completed(n,false);
    while(!bfs.empty())
    {
        c = bfs.front();
        //cout << "complete " << c << "\n";
        bfs.pop();
        completed[c] = true;
        ans.pb(c);
        for(int &i : el[c])
        {
            in_deg[i]--;
            if(!completed[i] && in_deg[i] == 0) bfs.push(i);
        }
    }
    if(ans.size() < n) cout <<  "IMPOSSIBLE";
    else for(int i : ans) cout << i << " ";
    return 0;
}
