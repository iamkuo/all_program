#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> diff(n+2,0);
    int l,r,w;
    for(int i=0;i<m;i++)
    {
        cin >> l >> r >> w;
        diff[l] += w;
        diff[r+1] -= w;
    }
    for(int i=2;i<=n;i++) diff[i] += diff[i-1];
    diff[0] = 1e9;
    diff[n+1] = 1e9;
    //for(int i : diff) cout << i << " ";
    //cout << "\n";
    sort(diff.begin(),diff.end());
    //for(int i : diff) cout << i << " ";
    //cout << "\n";
    vector<int> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    sort(t.begin(),t.end(),greater<int>());
    //for(int i : t) cout << i << " ";
    //cout << "\n";
    long long ans=0;
    for(int i=0;i<n;i++) ans += diff[i] * t[i];
    cout << ans;
    return 0;
}
