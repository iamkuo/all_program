#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> s(1e5+1,0);
    int n,tmp,max_s = -1,ans = -1;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        s[tmp]++;
        if(max_s < tmp) max_s = tmp;
    }
    vector<int> m(max_s+1,0);
    vector<int> is_prime(max_s+1,true);
    for(int i=2;i<=max_s;i++)
    {
        if(!is_prime[i]) continue;
        m[i] += s[i];
        for(int j=i+i;j<=max_s;j+=i)
        {
            m[i] += s[j];
            is_prime[j] = false;
        }
    }
    for(int i=2;i<=max_s;i++)
    {
        if(m[i] > ans) ans = m[i];
    }
    if(ans < 2) cout << 1;
    else cout << ans;
    return 0;
}
