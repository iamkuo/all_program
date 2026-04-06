#include <bits/stdc++.h>
using namespace std;

int to_index(int x)
{
    int ans;
    if(x >= 0) ans = x % 4;
    else ans = 4+x;
    //cout << ans << "\n";
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,sides[4];
    cin >> t;
    bool found;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        for(int j=0;j<4;j++) cin >> sides[j];
        for(int b=0;b<16;b++)
        {
            for(int k=0;k<4;k++)
            {
                if(b & (1 << k))
                {
                    sides[to_index(k)]--;
                    sides[to_index(k+1)]--;
                }
            }
            /*debug
            for(int i : sides) cout << i <<  " ";
            cout << "\n";
            //debug*/
            found=true;
            for(int k=0;k<4;k++)
            {
                if(sides[k] < 0 || sides[k] > n-2)
                {
                    found = false;
                    break;
                }
            }
            if(found)
            {
                cout << "YES" << "\n";
                break;
            }
            for(int k=0;k<4;k++)
            {
                if(b & (1 << k))
                {
                    sides[to_index(k)]++;
                    sides[to_index(k+1)]++;
                }
            }
        }
        if(!found)cout << "NO" << "\n";

    }
    return 0;
}
