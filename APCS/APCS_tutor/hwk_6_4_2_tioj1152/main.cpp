#include <bits/stdc++.h>
#define pb push_back
#define pii pair<uint16_t,uint16_t>
using namespace std;

vector<vector<uint16_t>> el;
uint16_t leaf;
uint16_t leaf_dist;

void dfs(uint16_t x,uint16_t parent,uint16_t curr)
{
    if(curr > leaf_dist)
    {
        leaf = x;
        leaf_dist = curr;
    }
    for(uint16_t i : el[x])
    {
        if(i != parent) dfs(i,x,curr+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    uint16_t n;
    cin >> n;
    el.resize(n);
    int tmp;
    for(uint16_t i=0;i<n;i++)
    {
        while(1)
        {
            cin >> tmp;
            if(tmp != -1)
            {
                //cout << "push " << i << " " << tmp << "\n";
                el[i].pb(tmp);
                el[tmp].pb(i);
            }
            else break;
        }
    }
    dfs(0,10001,0);
    leaf_dist = 0;
    dfs(leaf,10001,0);
    cout << leaf_dist;
    return 0;
}
