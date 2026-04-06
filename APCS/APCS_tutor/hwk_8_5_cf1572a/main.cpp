#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,k,tmp;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        vector<vector<int>> el(n+1); //DAG
        vector<int> in_deg(n+1);
        set<int> bfs;
        for(int j=1;j<=n;j++)
        {
            cin >> k;
            in_deg[j] = k;
            if(k==0) bfs.insert(j);
            for(int l=0;l<k;l++)
            {
                cin >> tmp;
                el[tmp].pb(j);
            }
        }
        int ans = 0,ok_cs = 0;
        int last_read = 1;
        while(!bfs.empty())
        {
            ans++;
            last_read = 1;
            while(1)
            {
                auto curr = bfs.lower_bound(last_read);
                if(curr == bfs.end()) break;
                int curr_val = *curr;
                ok_cs++;
                bfs.erase(curr);
                last_read = curr_val;
                for(int j : el[curr_val])
                {
                    in_deg[j]--;
                    if(in_deg[j] == 0) bfs.insert(j);
                }
            }
        }
        if(ok_cs == n) cout << ans;
        else cout << -1;
        cout << "\n";
    }
    return 0;
}
