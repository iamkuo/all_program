#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c;
    cin >> n;
    int dp[2][3];
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    int sth[3];
    for(int i=1;i<n;i++)
    {
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = 0;
        cin >> sth[0] >> sth[1] >> sth[2];
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(j==k) continue;
                dp[1][k] = max(dp[1][k],dp[0][j]+sth[k]);
                //cout << "trying transfer from " << j << " to " << k << "\n";
                //for(int i : dp[1]) cout << i << " ";
                //cout << "\n";
            }
        }
    }
    cout << max(dp[1][0],max(dp[1][1],dp[1][2]));
    return 0;
}
