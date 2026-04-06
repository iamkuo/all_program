#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

bool cmp(pii &a,pii &b) {return (1.0*a.f/a.s) < (1.0*b.f/b.s);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> items(n);
    for(int i=0;i<n;i++) cin >> items[i].f; //weight
    for(int i=0;i<n;i++) cin >> items[i].s; //take times
    sort(items.begin(),items.end(),cmp);
    int curr=0;
    unsigned long long ans=0;
    //for(pii i : items) cout << i.f << " " << i.s << "\n";
    for(int i=0;i<n;i++)
    {
        ans += (long long)curr * (long long)items[i].s;
        curr += items[i].f;
    }
    cout << ans;
    return 0;
}
