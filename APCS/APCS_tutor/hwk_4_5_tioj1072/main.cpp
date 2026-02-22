#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool compare(pair<int,int> &a,pair<int,int> &b) {return a.f > b.f;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,sum,ans;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        vector<pair<int,int>> eat(n);//(eat,cook)
        for(int i=0;i<n;i++) cin >> eat[i].s >> eat[i].f;
        sort(eat.begin(),eat.end(),compare);
        sum = 0;
        ans = -1;
        for(int i=0;i<n;i++)
        {
            sum += eat[i].s;
            if((sum+eat[i].f) > ans) ans = sum+eat[i].f;
        }
        cout << ans << "\n";
    }
    return 0;
}
