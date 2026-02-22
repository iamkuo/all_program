#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];//people
    for(int i=0;i<m;i++) cin >> b[i];//apartments
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int c_p=0, c_a=0, ans=0;
    while(c_p < n && c_a < m)
    {
        if(abs(a[c_p]-b[c_a]) <= k)
        {
            //cout << "person " << a[c_p] << " get in house " << b[c_a] << "\n";
            c_a ++;
            c_p ++;
            ans ++;
        }
        else
        {
            //cout << "person " << a[c_p] << " can't get in house " << b[c_a] << "\n";
            if(a[c_p] > b[c_a])  c_a ++;
            else c_p ++;
        }
    }
    cout << ans;
    return 0;
}
