#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

bool cmp(tiii &a, tiii &b) {return get<1>(a) < get<1>(b);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        vector<tiii> orders(n); //(start,stop,money)
        vector<int> dp(n+1,0);
        // (max price at first i orders)
        for(int j=0;j<n;j++)
        {
            cin >> get<0>(orders[j]);
            cin >> get<1>(orders[j]);
            cin >> get<2>(orders[j]);
        }
        sort(orders.begin(),orders.end(),cmp);
        vector<int> ends(n,0);
        for(int j=0;j<n;j++) ends[j] = get<1>(orders[j]);
        for(int j=1;j<=n;j++) // scan from dp[1]~dp[n]
        {
            //(start,finish,money)
            int &a = get<0>(orders[j-1]);
            int &b = get<1>(orders[j-1]);
            int &c = get<2>(orders[j-1]);
            int k = upper_bound(ends.begin(),ends.end(),a-1) - ends.begin();
            dp[j] = max(dp[j-1],dp[k]+c);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
