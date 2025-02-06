#include <bits/stdc++.h>

using namespace std;



int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int h[n],w[k];
    for (int i=0;i<n;i++)
    {
        cin >> h[i];
    }
    for (int i=0;i<k;i++)
    {
        cin >> w[i];
    }
    int l,r,m;
    l = h[0];
    r = h[0];
    for(int i=0;i<n;i++)
    {
        if(h[i] > r)
        {
            r = h[i];
        }
        if(h[i] < l)
        {
            l = h[i];
        }
    }
    while(l<=r)
    {
        int now = 0;
        m = (l+r)/2;
        bool can_place_all = true;
        for(int i=0;i<k;i++)
        {
            int now_length = 0;
            bool can_place_one = false;
            for(int j=now;j<n;j++)
            {
                if(h[j] > m)
                {
                    now_length ++;
                    if(now_length == w[i])
                    {
                        can_place_one = true;
                        now = j+1;
                        break;
                    }
                }
                else
                {
                    now_length = 0;
                }
            }
            if(can_place_one == false)
            {
                can_place_all = false;
                break;
            }
        }
        if(can_place_all)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }

    }
    cout << l-1;
    return 0;
}
