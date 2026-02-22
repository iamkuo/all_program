#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define f first
#define s second
#define pq priority_queue
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,c;
    cin >> n >> m;
    vector<vector<pii>> el(n+1);
    //(id,length)
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        el[a].pb({b,c});
    }
    pq<pli,vector<pli>,greater<pli>> bfs;
    //(distance to city 1,id)
    vector<ll> dist(n+1,-1);
    vector<bool> locked(n+1, false);
    dist[1] = 0;
    bfs.push({0,1});
    while(!bfs.empty())
    {
        auto [d,curr_id] = bfs.top();
        bfs.pop();
        if(locked[curr_id]) continue;
        locked[curr_id] = true;
        for(auto &[next_id,w] : el[curr_id])
        {
            ll &next_dist = dist[next_id];
            if(next_dist == -1 || d + w < next_dist)
            {
                next_dist = d + w;
                bfs.push({d + w,next_id});
            }
        }
    }
    for(int i=1;i<=n;i++) cout << dist[i] << " ";
    return 0;
}
