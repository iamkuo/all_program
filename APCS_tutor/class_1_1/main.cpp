#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p[20];
    long long int l,r,min_diff = 3e10;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<(1 << n);i++)
    {
        l=0;
        r=0;
        for(int j=0;j<n;j++)
        {
            if(1 & (i >> j)) l += p[j];
            else r += p[j];
        }
        //cout << abs(l-r) << "\n";
        if(abs(l-r) < min_diff) min_diff = abs(l-r);
    }
    cout << min_diff;
    return 0;
}
