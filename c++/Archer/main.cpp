#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class sun
{
public:
    int x;
    int y;
    int L;
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int x0,y0,L0,r;
    cin >> x0 >> y0 >> L0 >> r;
    int n;
    cin >> n;
    int ans = 0;
    sun suns[n];
    for(int i=0;i<n;i++)
    {
        cin >> suns[i].x >> suns[i].y >> suns[i].L;
    }
    for(int i=0;i<n;i++)
    {
        if(L0>=suns[i].L)
        {
            if((abs(suns[i].x-x0)*abs(suns[i].x-x0)+abs(suns[i].y-y0)*abs(suns[i].y-y0))<r*r)
            {
                //cout << "shooted" << i << endl;
                ans ++;
            }
        }
    }
    cout << ans;



}
