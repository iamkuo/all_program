#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,P;
    cin >> n >> P;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    long long int sum,ans = -1;
    for(long long int i=0;i<(1 << n);i++)
    {
        sum = 0;
        for(int j=0;j<n;j++) if(i & (1 << j)) sum += x[j];
        //cout << "sum=" << sum << "\n";
        if(ans < sum && sum < P)
        {
            ans = sum;
            //cout << "change to " << ans << " at " << bt << "\n";
        }
    }
    cout << ans;
    return 0;
}
