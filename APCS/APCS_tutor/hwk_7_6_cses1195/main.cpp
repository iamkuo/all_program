#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define pq priority_queue
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> el(2*n+1); //(id,c)
    int a,b;
    ll c;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        el[a].pb({b,c});
        el[a+n].pb({b+n,c});
        el[a].pb({b+n,c/2});
    }
    vector<ll> dist(2*n+1,1e18);
    //(no coupon,with coupon)
    dist[1] = 0;
    pq<pli,vector<pli>,greater<pli>> bfs;
    //(dist,id)
    bfs.push({0,1});
    while(!bfs.empty())
    {
        auto [curr_dist, curr_id] = bfs.top();
        bfs.pop();
        if(curr_dist > dist[curr_id]) continue; //curr_dist is outdated
        for(auto &[next_id,x] : el[curr_id])
        {
            if(dist[next_id] > curr_dist+x)
            {
                dist[next_id] = curr_dist+x;
                bfs.push({dist[next_id],next_id});
            }
        }
    }
    cout << dist[n*2];
    return 0;
}
