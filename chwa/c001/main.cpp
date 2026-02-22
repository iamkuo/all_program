#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool if_prime[1000001];//prime count <= i,0=false,1=true
    for(int i=0;i<=1000000;i++) if_prime[i] = true;
    int p_sum[1000001];
    p_sum[0] = 0;
    p_sum[1] = 0;
    for(int i=2;i*i<=1000000;i++)
    {
        if(!if_prime[i]) continue;
        //cout << "all beishu of " << i << " is not a prime\n";
        for(int j = i*i;j<=1000000;j+=i)
        {
          if_prime[j] = false;
        }
    }
    p_sum[0] = p_sum[1] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        p_sum[i] = p_sum[i - 1] + (if_prime[i] ? 1 : 0);
    }
    int n,a,b;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        //cout << p_sum[b]  << " " << p_sum[a-1] << "\n";
        cout << p_sum[b] - p_sum[a-1] << "\n";
    }
    return 0;
}
