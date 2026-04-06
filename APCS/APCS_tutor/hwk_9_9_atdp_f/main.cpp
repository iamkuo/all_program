#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    vector<vector<int>> parent(s.size()+1,vector<int>(t.size()+1,-1));
    //0=up left, 1=up, 2=left
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=t.size();j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                parent[i][j] = 0;
            }
            else
            {
                if(dp[i-1][j] >= dp[i][j-1])
                {
                    dp[i][j] = dp[i-1][j];
                    parent[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                    parent[i][j] = 2;
                }
            }
        }
    }
    string ans = "";
    int i=s.size(),j=t.size();
    while(i > 0 && j > 0)
    {
        if(parent[i][j] == 0)
        {
            ans += s[i-1];
            i--;
            j--;
        }
        else if(parent[i][j] == 1) i--;
        else j--;
    }
    for(int i=ans.size()-1;i >= 0;i--) cout << ans[i];
    return 0;
}
