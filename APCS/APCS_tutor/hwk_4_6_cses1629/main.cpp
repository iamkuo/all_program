#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;

bool compare(pii &a, pii &b) {return a.s < b.s;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> movies(n);
    for(int i=0;i<n;i++) cin >> movies[i].f >> movies[i].s;
    sort(movies.begin(),movies.end(),compare);
    int last = -1;// last occupied time
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(last <= movies[i].f)
        {
            //cout << "watch " << i << " end at " << movies[i].s << "\n";
            ans++;
            last = movies[i].s;
        }
    }
    cout << ans;
    return 0;
}
