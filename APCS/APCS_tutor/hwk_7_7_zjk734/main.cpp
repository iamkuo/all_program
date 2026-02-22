#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,t,tmp;
    cin >> n >> m >> k >> t;
    //which boxes can key i open
    vector<vector<int>> open(m);
    //which keys does each box contain
    vector<vector<int>> boxes(n,vector<int>(k));
    vector<int> needed(n,k);
    vector<bool> has_key(m,false);
    //boxes that are already opened
    queue<int> bfs;
    vector<int> init_keys(t);
    for(int i=0;i<t;i++) cin >> init_keys[i];
    //records what boxes can each key open
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin >> tmp;
            open[tmp].pb(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++) cin >> boxes[i][j];
    }
    for(int key_id : init_keys)
    {
        if(has_key[key_id]) continue;
        has_key[key_id] = true;
        for(int &box : open[key_id])
        {
            if(--needed[box] == 0)
            {
                bfs.push(box);
            }
        }
    }
    int ans=0;
    while(!bfs.empty())
    {
        int curr = bfs.front();
        //opens the box
        bfs.pop();
        ans++;
        //cycles through every keys in this box
        for(int i=0;i<k;i++)
        {
            int &next_key = boxes[curr][i];
            if(has_key[next_key]) continue;
            has_key[next_key]=true;
            //cycles through every boxes that this key can open
            for(int &box : open[next_key])
            {
                if(--needed[box] == 0) bfs.push(box);
            }
        }
    }
    cout << ans;
    return 0;
}
