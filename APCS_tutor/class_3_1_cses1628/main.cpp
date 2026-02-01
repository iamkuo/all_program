#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,l_len,r_len;
    long long x,tmp,ans=0;
    vector<long long> l,r;
    cin >> n >> x;
    l_len = pow(2,n/2);
    r_len = pow(2,n-n/2);
    vector<long long> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<l_len;i++)
    {
        tmp = 0;
        for(int j=0;j<n/2;j++)
        {
            if(1 << j & i) tmp += t[j];
        }
        if (tmp <= x) l.push_back(tmp);
    }
    sort(l.begin(),l.end());
    for(int i=0;i<r_len;i++)
    {
        tmp = 0;
        for(int j=0;j<(n-n/2);j++)
        {
            if(1 << j & i) tmp += t[j+n/2];
        }
        if (tmp <= x) r.push_back(tmp);
    }
    sort(r.begin(),r.end());
    //ans += l[x] + r[x];
    for(long long i : l)
    {
        if (i > x) break;
        ans += upper_bound(r.begin(),r.end(),x-i)-lower_bound(r.begin(),r.end(),x-i);
    }
    //for(auto i : l) cout << i << " ";
    //cout << "\n";
    //for(auto i : r) cout << i << " ";
    //cout << "\n";
    cout << ans;
    return 0;
}
