#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> stones(n+1);
    vector<int> dp(n+1,2e9);
    dp[1] = 0;
    //for(int i : dp) cout << i << " ";
    //cout << "\n";
    for(int i=1;i<=n;i++) cin >> stones[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=max(1,i-2);j<i;j++)
        {
            //cout << "checking " << j << " jump to " << i << "\n";
            dp[i] = min(dp[i],dp[j]+abs(stones[i]-stones[j]));
            //for(int i : dp) cout << i << " ";
            //cout << "\n";
        }
    }
    cout << dp[n];
    return 0;
}
