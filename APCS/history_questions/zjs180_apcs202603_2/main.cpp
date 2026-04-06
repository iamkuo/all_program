#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> t(n);
    vector<int> s(m);
    vector<int> e(m);
    set<int> u_pos;
    map<int,int> pos_ref;
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        u_pos.insert(t[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin >> s[i] >> e[i];
        u_pos.insert(s[i]);
        u_pos.insert(e[i]);
    }
    int idx = 1;
    for(int i : u_pos)
    {
        pos_ref[i] = idx;
        idx ++;
    }
    int max_date = u_pos.size()+1;
    vector<int> p_sum(max_date+1,0);
    for(int i=0;i<m;i++)
    {
        p_sum[pos_ref[s[i]]] ++;
        p_sum[pos_ref[e[i]]+1] --;
    }
    for(int i=1;i<=max_date;i++) p_sum[i] += p_sum[i-1];
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += p_sum[pos_ref[t[i]]];
    }
    //for(int i : p_sum) cout << i << " ";
    //cout << "\n";
    cout << ans;
    return 0;
}
