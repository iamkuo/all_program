#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m = 1e9+7;
    int n;
    cin >> n;
    vector<long long> dp(n+1,0);
    for(int i=1;i<=min(6,n);i++) dp[i] = 1;
    long long p_sum;
    for(int i=2;i<=n;i++)
    {
        p_sum=0;
        for(int j=max(1,i-6);j<i;j++) dp[i] += dp[j];
        p_sum += dp[i];
        dp[i] %= m;
        p_sum %= m;
    }
    //for(int i : dp) cout << i << " ";
    //cout << "\n";
    cout << dp[n];
    return 0;
}
