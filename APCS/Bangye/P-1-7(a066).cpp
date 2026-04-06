#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> x;
    int n;
    cin >> n;
    x.resize(n);
    for(int i=0;i<n;i++) cin >> x[i];
    int m,ans = 0;
    for(int i=1;i<=(1 << n);i++)
    {
        m = 1;
        for(int j=0;j<n;j++)
        {
            cout << (i 1 << j)
            if(i & (1 << j)) m = m*x[j]%10009;
        }
        if(m == 1) ans ++;
    }
    cout << ans;
    return 0;
}
