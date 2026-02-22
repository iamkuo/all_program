#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,-1));
    // (id,c)
    int a,b;
    ll c;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        if(dist[a][b] == -1) dist[a][b] = c;
        else dist[a][b] = min(dist[a][b],c);
        if(dist[b][a] == -1) dist[b][a] = c;
        else dist[b][a] = min(dist[b][a],c);
    }
    for(int i=1;i<=n;i++)
    {
        dist[i][i] = 0;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(dist[j][i] > 0 && dist[i][k] > 0)
                {
                    if(dist[j][k] == -1) dist[j][k] = dist[j][i] + dist[i][k];
                    else dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
    return 0;
}
