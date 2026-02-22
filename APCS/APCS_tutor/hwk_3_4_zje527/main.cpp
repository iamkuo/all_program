#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    while((x %= y) && (y %= x));
    return x+y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dist[1026][1026];
    int n,x,y,z,f,s,t,ans;
    pair<int,int> fp;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> z;
        if (z > max(x, y) || z % gcd(x, y) != 0) {
            cout << -1 << '\n';
            continue;
        }
        queue<pair<int,int>> bfs;
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= y; j++)
                dist[i][j] = -1;
        bfs.push({0, 0});
        dist[0][0] = 0;
        ans = -1;
        while (!bfs.empty()) {
            fp = bfs.front();
            f = fp.first;
            s = fp.second;
            if (f == z || s == z) {
                ans = dist[f][s];
                break;
            }
            bfs.pop();
            //¥ª­Ëº¡
            if (dist[x][s] == -1) {
                dist[x][s] = dist[f][s] + 1;
                bfs.push({x, s});
            }
            //¥k­Ëº¡
            if (dist[f][y] == -1) {
                dist[f][y] = dist[f][s] + 1;
                bfs.push({f, y});
            }
            //¥ª­ËªÅ
            if (dist[0][s] == -1) {
                dist[0][s] = dist[f][s] + 1;
                bfs.push({0, s});
            }
            //¥k­ËªÅ
            if (dist[f][0] == -1) {
                dist[f][0] = dist[f][s] + 1;
                bfs.push({f, 0});
            }
            //¥ª­Ë¥k
            int t = min(f, y - s);
            if (dist[f - t][s + t] == -1) {
                dist[f - t][s + t] = dist[f][s] + 1;
                bfs.push({f - t, s + t});
            }
            //¥k­Ë¥ª
            t = min(s, x - f);
            if (dist[f + t][s - t] == -1) {
                dist[f + t][s - t] = dist[f][s] + 1;
                bfs.push({f + t, s - t});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
