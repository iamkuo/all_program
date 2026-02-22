#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<bool> connected;
//if this house is connected to house 1, originally set to false
vector<vector<int>> roads;
//edge list
vector<int> ans;

// mark all the houses that has a connection with house x
void dfs(int x)
{
    vector<int> &dest = roads[x];
    //all the houses that house x already connects with
    for(int i=0;i<dest.size();i++)
    {
        if(!connected[dest[i]])
        {
            connected[dest[i]] = true;
            dfs(dest[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    connected.resize(n+1,false);
    roads.resize(n+1);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    connected[1] = true;
    dfs(1);
    for(int i=2;i<=n;i++)
    {
        if(connected[i]) continue;
        ans.push_back(i);
        connected[i] = true;
        dfs(i);
    }
    cout << ans.size() << "\n";
    for(int i : ans) cout << 1 << " " << i << "\n";
    return 0;
}
