#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x;
    cin >> x;
    int l=0,r=1,ans=1;
    while(r < x.size())
    {
        if(x[r] != x[r-1]) l = r;
        if((r-l+1) > ans) ans = r-l+1;
        r++;
    }
    cout << ans;
    return 0;
}
