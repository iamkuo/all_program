#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define pii pair<int,int>
#define pll pair<long long,long long>
#define tiii tuple<int,int,int>
#define f first
#define s second

const long long INF = 1e18;

vector<tiii> edges;
vector<vector<pll>> adj;
vector<vector<pll>> rev_adj;
vector<long long> d1;
vector<long long> dn;

void dijkstra(int start, vector<long long>& dist, vector<vector<pll>>& graph)
{
    dist.assign(dist.size(), INF);
    dist[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& edge : graph[u])
        {
            int v = edge.f;
            int w = edge.s;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    d1.resize(n + 1);
    dn.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, (long long)w});
        rev_adj[v].push_back({u, (long long)w});
    }

    dijkstra(1, d1, adj);
    dijkstra(n, dn, rev_adj);

    long long ans = INF;
    for (auto& e : edges)
    {
        auto [u, v, w] = e;
        if (d1[u] != INF && dn[v] != INF)
            ans = min(ans, d1[u] + (w / 2) + dn[v]);
    }

    cout << ans << "\n";

    return 0;
}
