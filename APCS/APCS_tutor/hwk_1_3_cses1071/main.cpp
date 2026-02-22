#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long int ans,x,y;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> y >> x;
        if (x >= y)
        {
            if(x%2)
            {
                //
                ans = x*x - y + 1;
            }
            else
            {
                //
                ans = (x-1)*(x-1) + y;
            }
        }
        else
        {
            if(y%2)
            {
                //
                ans = (y-1)*(y-1) + x;
            }
            else
            {
                //
                ans = y*y - x + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
