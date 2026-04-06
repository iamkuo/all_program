#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(x+1,1e6+1);
    dp[0] = 0;
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
        if(coins[i] < x) dp[coins[i]] = 1;
    }
    sort(coins.begin(),coins.end());
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j] > i) break;
            dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
    cout << ((dp[x] == 1e6+1) ? -1 : dp[x]);
    return 0;
}
