#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second

bool compare(pll &a,pll &b) {return a.f < b.f;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pll> tasks(n);//(duration,reward)
    for(int i=0;i<n;i++) cin >> tasks[i].f >> tasks[i].s;
    sort(tasks.begin(),tasks.end(),compare);
    ll ans = 0,time = 0;//last time not occupied
    for(int i=0;i<n;i++)
    {
        time += tasks[i].f;
        ans += tasks[i].s - time;
    }
    cout << ans;
    return 0;
}
