#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<long long> dp(x+1,0);
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
        if(coins[i] <= x)dp[coins[i]]++;
    }
    sort(coins.begin(),coins.end());
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(coins[j] > i) break;
            dp[i] += dp[i-coins[j]];
        }
        dp[i] %= (int)(1e9+7);
    }
    //for(int i : dp) cout << i << " ";
    //cout << "\n";
    cout << dp[x];
    return 0;
}
