#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

int n,k;
multiset<int> people;//last occupied time of person i

bool cmp(pii &a,pii &b) {return a.s < b.s;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans=0;
    cin >> n >> k;
    vector<pii> movies(n);
    for(int i=0;i<k;i++) people.insert(0);
    for(int i=0;i<n;i++) cin >> movies[i].f >> movies[i].s; //(start,end)
    sort(movies.begin(),movies.end(),cmp);
    for(int i=0;i<n;i++)
    {
        if(*people.begin() > movies[i].f) continue;
        //if(free_person == people.begin()) continue;
        auto free_person = people.upper_bound(movies[i].f);
        people.erase(--free_person);
        people.insert(movies[i].s);
        ans ++;
    }
    cout << ans;
    return 0;
}
