#include <bits/stdc++.h>
#define f front
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,ans=0;
    cin >> n;
    vector<vector<int>> el(n+1);
    vector<int> branch(n+1,0);
    vector<bool> exist(n+1,false);
    for(int i=1;i<=n-1;i++)
    {
        cin >> a >> b;
        exist[a] = true;
        exist[b] = true;
        el[a].push_back(b);
        el[b].push_back(a);
        branch[a]++;
        branch[b]++;
    }
    bool done = false;
    queue<int> bfs;
    for(int i=1;i<=n;i++)
    {
        if(branch[i] == 1) bfs.push(i);
    }
    while(!bfs.empty())
    {
        int curr = bfs.f();
        bfs.pop();
        if(!exist[curr]) continue;
        exist[curr] = false;
        int v = -1;
        for (int x : el[curr])
        {
            if (exist[x])
            {
                v = x;
                break;
            }
        }
        if (v == -1) continue;
        ans++;
        exist[v] = false;
        for (int x : el[v])
        {
            if (exist[x])
            {
                branch[x]--;
                if (branch[x] == 1) bfs.push(x);
            }
        }
    }
    cout << ans;
    return 0;
}
