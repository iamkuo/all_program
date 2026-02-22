#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n;
    long long sum=0,ans=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        sum += x;
        if(sum > ans) ans=sum;
        if(sum <= 0) sum = 0;
    }
    cout << ans;
    return 0;
}
