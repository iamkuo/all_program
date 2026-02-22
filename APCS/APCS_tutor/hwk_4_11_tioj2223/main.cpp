#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;

bool cmp(pii &a,pii &b) {return a.s > b.s;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=0;
    cin >> n >> m;
    vector<pii> rocks(n);//(weight,price per unit)
    for(int i=0;i<n;i++) cin >> rocks[i].f >> rocks[i].s;
    sort(rocks.begin(),rocks.end(),cmp);
    for(int i=0;i<n;i++)
    {
        if(rocks[i].f <= m)
        {

            ans += rocks[i].f*rocks[i].s;
            m -= rocks[i].f;
        }
        else
        {
            cout << ans + rocks[i].s * m;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
